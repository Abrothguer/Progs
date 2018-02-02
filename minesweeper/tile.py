#!/usr/bin/env Python 2.7
""" Implements the Tile class and it's methods """

import Tkinter as tk


class Tile(tk.Button):
    """ This class represents a tile on a minesweeper field """

    def __init__(self, parent, position, danger):
        """ Initialize the button with the position and danger """
        tk.Button.__init__(self, parent, height=1, foreground='red', width=1, background='blue',
                           activebackground='blue', disabledforeground='red')
        self.__position = position
        self.__danger = danger
        self.__flagged = False
        self.__visible = False

    def get_position(self):
        """ Returns the position of the tile on the grid """
        return self.__position

    def get_flagged(self):
        """ Returns if the tile is flagged or not """
        return self.__flagged

    def get_danger(self):
        """ Returns the danger of the tile, Bomb -> danger = 9 """
        return self.__danger

    def get_visible(self):
        """ Returns if the button is visible or not """
        return self.__visible

    def increment_danger(self):
        """ Increments the __danger variable """
        self.__danger += 1

    def mark_bomb(self):
        """ Defines the tile as a bomb """
        self.__danger = 9

    def toggle_flag(self):
        """ Toggle the flag of the tile """
        if self.__flagged is False:
            self.config(text='?', foreground='black')
        else:
            self.config(text='')

        self.__flagged = not self.__flagged
        return self.__flagged

    def show_tile(self):
        """ Show the tile text and disables it """
        if self.__danger > 8:
            self.config(text='X')
        elif self.__danger is not 0:
            self.config(text=str(self.__danger))

        self.config(background='gray', activebackground='gray')
        self.__disable()
        self.__visible = True

        return self.__danger

    def hide_tile(self):
        """ Hides the tile """

        self.__enable()
        self.config(text='', background='blue', activebackground='blue')
        self.__visible = False

    def halt_tile(self):
        """ Halts the tile, disable normal and show bomb """

        if self.__visible is True:
            return
        if self.__danger > 8:
            self.config(text='X')
        elif self.__danger is not 0:
            self.config(text=str(self.__danger))

        self.__disable()
        self.__visible = True

    def __disable(self):
        """ Disable the button """
        self.config(state='disabled')


    def __enable(self):
        """ Enable the button """
        self.config(state='normal')
