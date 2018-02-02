#!/usr/bin/env Python 2.7
""" Main Minesweeper Program"""

import Tkinter as tk
import tkMessageBox
import tkSimpleDialog
import gameframe


class ChangeGridWindow(tkSimpleDialog.Dialog):
    """ Show the window for the user to change the size of the grid """

    def body(self, master):
        self.xlabel = tk.Label(master, text='Number of rows: ')
        self.ylabel = tk.Label(master, text='Number of columns: ')

        self.xentry = tk.Entry(master)
        self.yentry = tk.Entry(master)

        self.xlabel.grid(row=0, column=0)
        self.ylabel.grid(row=0, column=1)
        self.xentry.grid(row=1, column=0)
        self.yentry.grid(row=1, column=1)

    def apply(self):
        xmax = self.xentry.get()
        ymax = self.yentry.get()
        self.result = xmax, ymax

class GameStandarts(object):
    """ Defines variables for the game, these variables can be changed by the user """

    def __init__(self):
        self.__yaxis = 10
        self.__xaxis = 10
        self.__level = 'easy'
        self.__new_game = False
        self.__restart = False

    def get_size(self):
        """ Get the defined size """
        return (self.__xaxis, self.__yaxis)

    def set_yaxis(self, num):
        """ Sets the value of the yaxis """
        self.__yaxis = num

    def set_xaxis(self, num):
        """ Sets the value of the xaxis """
        self.__xaxis = num

    def get_level(self):
        """ Returns the defined level """
        return self.__level

    def change_level(self, new_level):
        """ Change the current level """
        self.__level = new_level

    def get_new_game(self):
        """ Gets the status of the __new_game variable """
        return self.__new_game

    def set_new_game(self, value):
        """ Sets the value of the __new_game variable """
        self.__new_game = value

    def get_restart(self):
        """ Gets the status of the __restart variable """
        return self.__restart

    def set_restart(self, value):
        """ Sets the value of the __restart variable """
        self.__restart = value


class DropDownMenu(tk.Menu):
    """ Implements the drop down menus and its function """

    def __init__(self, standart, parent=None):
        tk.Menu.__init__(self, parent)
        self.exit_status = False
        self.standart = standart

        # Game Options Drop Down Menu
        self.sub_game = tk.Menu(self)
        self.add_cascade(label='Game Options', menu=self.sub_game)

        # Level Options Drop Down Menu
        self.sub_level = tk.Menu(self)
        self.sub_game.add_cascade(label='Change level', menu=self.sub_level)
        self.sub_level.add_command(label='Easy', command=self.set_easy)
        self.sub_level.add_command(label='Medium', command=self.set_medium)
        self.sub_level.add_command(label='Hard', command=self.set_hard)

        # Size Options New Frame
        self.sub_game.add_command(label='Change grid size', command=self.show_size_panel)

        # Add Separator, Restart and New Game commands
        self.sub_game.add_separator()
        self.sub_game.add_command(label='Restart game', command=self.restart)
        self.sub_game.add_command(label='New game', command=self.new_game)

        # Add Separator and Exit label
        self.sub_game.add_separator()
        self.sub_game.add_command(label='Exit', command=self.exit)


    def show_size_panel(self):
        """ Show the panel for the user to modify the grid size """
        size_panel = ChangeGridWindow(self)
        if size_panel.result is None:
            return
        xpos, ypos = size_panel.result
        try:
            xpos = int(xpos)
            ypos = int(ypos)
        except ValueError:
            tkMessageBox.showerror(title='Error', message='Informed values are not valid' +
                                   'Please type only integers!')
            return
        if xpos <= 0 or ypos <= 0 or xpos > 100 or ypos > 100:
            tkMessageBox.showerror(title='Error', message='Informed values are not valid' +
                                   'Please inform values between 0 and 100!')
            return
        self.standart.set_xaxis(xpos)
        self.standart.set_yaxis(ypos)
        self.ask_for_newgame()

    def set_easy(self):
        """ Sets the level to easy """
        self.standart.change_level('easy')
        self.ask_for_newgame()

    def set_medium(self):
        """ Sets the level to medium """
        self.standart.change_level('medium')
        self.ask_for_newgame()

    def set_hard(self):
        """ Sets the level to hard """
        self.standart.change_level('hard')
        self.ask_for_newgame()

    def exit(self):
        """ Change the exit_status variable therefore ending the program """
        self.exit_status = True

    def ask_for_newgame(self):
        """ Ask the user for the game to restart """
        answer = tkMessageBox.askquestion(title='New Game', message='Start new game to apply ' +
                                          'changes? If you do not wish to restart your game the' +
                                          ' changes will be apllied on next game you start')

        if answer == 'yes':
            self.standart.set_new_game(True)

    def get_exit_status(self):
        """ Returns the exit status """
        return self.exit_status

    def new_game(self):
        """ Sets the new_game variable to true """
        self.standart.set_new_game(True)

    def restart(self):
        """ Sets the restart variable to true """
        self.standart.set_restart(True)


def main():
    """ Creates the window, its menus and initializes the game """

    window = tk.Tk()
    window.title('Minesweeper')

    standart = GameStandarts()
    game = gameframe.GameFrame(standart.get_level(), standart.get_size(), window)
    game.pack()

    menu = DropDownMenu(standart, window)
    window.config(menu=menu)

    while menu.get_exit_status() is False:
        window.update_idletasks()
        window.update()

        if game.get_result() is not None:
            if game.get_result() is True:
                tkMessageBox.showinfo(title='Congratulations', message='You Win!')
            else:
                tkMessageBox.showinfo(title='Better luck next time', message='You lose!')
            answer = tkMessageBox.askyesno(title='New Game', message='Start new game?')

            if answer is False:
                game.halt()
                continue
            game.pack_forget()
            print 'stans lev {} and siz {}'.format(standart.get_level(), standart.get_size())
            game = gameframe.GameFrame(standart.get_level(), standart.get_size(), window)
            game.pack()

        if standart.get_new_game() is True:
            game.pack_forget()
            print 'stans lev {} and siz {}'.format(standart.get_level(), standart.get_size())
            game = gameframe.GameFrame(standart.get_level(), standart.get_size(), window)
            print 'got ourselves a new game'
            game.pack()
            print 'packed just fine'
            standart.set_new_game(False)

        if standart.get_restart() is True:
            game.hideall()
            standart.set_restart(False)

    window.destroy()


if __name__ == '__main__':
    main()
