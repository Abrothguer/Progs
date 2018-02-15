#!/usr/bin/env Python 2.7
""" Implements the grid frame - where the game happens """

from random import randint
import Tkinter as tk
import tile


class MineGrid(tk.Frame):
    """ Implements the Minefield grid and its methods """

    def __init__(self, gridsize, parent=None):
        tk.Frame.__init__(self, parent)
        self.fieldsize = gridsize
        self.minefield = []
        self.make_grid()

    def make_grid(self):
        """ Makes the minefield grid """
        maxx, maxy = self.fieldsize

        for i in range(0, maxx):
            buttonlist = []
            for j in range(0, maxy):
                button = tile.Tile(self, (i, j), 0)
                button.grid(row=i, column=j)
                buttonlist.append(button)
            self.minefield.append(buttonlist)

    def set_commands(self, right_click_command, left_click_command):
        """ Sets the commands for each button on the minefield """
        maxx, maxy = self.fieldsize

        for i in range(0, maxx):
            for j in range(0, maxy):
                position = self.minefield[i][j].get_position()
                self.minefield[i][j].bind('<Button-1>', lambda event, pos=position:
                                          right_click_command(pos))
                self.minefield[i][j].bind('<Button-3>', lambda event, pos=position:
                                          left_click_command(pos))

    def show_tile(self, coords):
        """ Try to show the specified tile """
        posx, posy = coords
        if self.minefield[posx][posy].get_flagged() is True:
            return -1
        if self.minefield[posx][posy].get_visible() is True:
            return -1
        danger = self.minefield[posx][posy].show_tile()
        return danger

    def flag_tile(self, coords):
        """ Flag or unflag the tile """

        posx, posy = coords
        if self.minefield[posx][posy].get_visible() is True:
            return 0
        self.minefield[posx][posy].toggle_flag()
        if self.minefield[posx][posy].get_flagged() is True:
            return -1
        return 1

    def reveal_blanks(self, coords):
        """ Reveal the blanks and the tiles around it {RECURSIVE} """

        maxx, maxy = self.fieldsize
        posx, posy = coords

        if posx >= maxx or posy >= maxy or posx < 0 or posy < 0:
            return 0
        if self.minefield[posx][posy].get_flagged() is True:
            return 0

        danger = self.minefield[posx][posy].show_tile()
        if danger != 0:
            return 1

        revealed = 0
        for i in range(-1, 2):
            for j in range(-1, 2):
                if i is 0 and j is 0:
                    continue
                if posx + i < 0 or posy + j < 0 or posx + i >= maxx or posy + j >= maxy:
                    continue
                if self.minefield[posx + i][posy + j].get_visible() is True:
                    continue

                self.minefield[posx + i][posy + j].show_tile()
                revealed += self.reveal_blanks((posx + i, posy + j))

        return revealed + 1

    def generate_mines(self, level):
        """ Generate the mines randomly on the field """

        posx, posy = self.fieldsize
        total_tiles = posx * posy

        if level == 'easy':
            total_mines = 0.10 * total_tiles
        elif level == 'medium':
            total_mines = 0.30 * total_tiles
        elif level == 'hard':
            total_mines = 0.70 * total_tiles
        total_mines = round(total_mines)
        holder = total_mines

        while total_mines != 0:
            coordx = randint(0, posx - 1)
            coordy = randint(0, posy - 1)

            if self.minefield[coordx][coordy].get_danger() >= 9:
                continue

            self.minefield[coordx][coordy].mark_bomb()

            for i in range(-1, 2):
                for j in range(-1, 2):
                    if i is 0 and j is 0:
                        continue
                    if coordx + i < 0 or coordy + j < 0 or coordx + i >= posx or coordy + j >= posy:
                        continue
                    self.minefield[coordx + i][coordy + j].increment_danger()

            total_mines -= 1

        return holder

    def hideall(self):
        """ Hides all the tiles """
        posx, posy = self.fieldsize

        for i in range(0, posx):
            for j in range(0, posy):
                self.minefield[i][j].hide_tile()

    def haltall(self):
        """ Halt all the tiles """
        posx, posy = self.fieldsize

        for i in range(0, posx):
            for j in range(0, posy):
                self.minefield[i][j].halt_tile()


class ControlPanel(tk.Frame):
    """ Implements the control panel """

    def __init__(self, parent=None):
        tk.Frame.__init__(self, parent)
        self.bomblabel = tk.Label(self)
        self.bomblabel.pack()

    def change_text(self, num):
        """ Changes the text on the bomb label """
        self.bomblabel.config(text='Bombs left {}'.format(num))


class GameFrame(tk.Frame):
    """ Condenses the MineGrid and ControlPanel classes into one """

    def __init__(self, level, gridsize, parent=None):
        tk.Frame.__init__(self, parent)
        self.field = MineGrid(gridsize, self)
        self.score = ControlPanel(self)
        self.result = None
        self.mines = self.field.generate_mines(level)
        self.normal_tiles = (gridsize[0] * gridsize[1]) - self.mines
        self.tiles_showed = 0
        self.score.change_text(self.mines)
        self.field.set_commands(self.show_command, self.flag_command)

        self.field.pack()
        self.score.pack()

    def show_command(self, position):
        """ Command called by a grid button when left-clicked """

        danger = self.field.show_tile(position)
        if danger == -1:
            return
        elif danger is 0:
            revealed = self.field.reveal_blanks(position)
            self.tiles_showed += revealed
            if self.tiles_showed == self.normal_tiles:
                self.result = True
        elif danger >= 9:
            self.result = False
        else:
            self.tiles_showed += 1
            if self.tiles_showed == self.normal_tiles:
                self.result = True

    def hideall(self):
        """ Calls the command to hide all the tiles on the grid """
        self.field.hideall()

    def flag_command(self, position):
        """ Command called by a grid button when right-clicked """

        toggle = self.field.flag_tile(position)
        self.mines += toggle
        self.score.change_text(self.mines)

    def get_result(self):
        """ Gets the value of the result variable """

        return self.result

    def halt(self):
        """ Halts the game """

        self.result = None
        self.field.haltall()
