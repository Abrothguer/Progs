#!/usr/bin/python3

""" Main window interface """

import tkinter as tk
from canvas import GameCanvas


class MainWindow(tk.Tk):
    """ Implements the game main window """

    def __init__(self):

        tk.Tk.__init__(self)
        self.title('Arkanoid')
        self.geometry('300x550')
        self.resizable(False, False)

        self.main_frame = tk.Frame(self, bg='black', bd=5, highlightcolor='red')
        self.main_frame.pack(fill=tk.BOTH, expand=True)

        self.game_canvas = GameCanvas(self.main_frame, 300, 500)
        self.game_canvas.pack()

        self.new_game = tk.Button(self.main_frame, text='New Game', command=self.__new_game)
        self.new_game.pack(pady=6)

    def __new_game(self):
        """ Starts a new game """

        self.game_canvas.pack_forget()
        del self.game_canvas
        self.game_canvas = GameCanvas(self.main_frame, 300, 500)
        self.new_game.pack_forget()
        self.game_canvas.pack()
        self.new_game.pack(pady=6)
        self.game_canvas.play()


def main():
    """ Creates a window and displays the game """

    window = MainWindow()
    window.mainloop()


if __name__ == "__main__":
    main()
