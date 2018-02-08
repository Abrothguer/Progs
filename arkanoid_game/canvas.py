#!/usr/bin/python3

""" Canvas class where the game takes place """

import tkinter as tk
import player as pl
import target as tg
import ball as bl


class GameCanvas(tk.Canvas):  # pylint: disable=too-many-ancestors
    """ Implements the Canvas where the game is contained """

    def __init__(self, parent, width, height):

        # Canvas configurations
        tk.Canvas.__init__(self, parent, width=width, height=height, bg='black', cursor='none')
        self.canvassize = (width, height)
        self.parent = parent
        self.result = None

        # Canvas objects
        self.player = pl.Player(self)
        self.targets = self.generate_targets()
        self.ball = bl.Ball(self, 10, self.canvassize)

        # Binds
        self.bind('<Motion>', self.player.move_player)

    def generate_targets(self):
        """ Generates the list of targets """

        tg_list = []

        size_x = self.canvassize[0] // 5
        size_y = 20

        for i in range(0, 3):
            for j in range(0, 5):

                bbox = (j * size_x + 1, i * size_y + 50 + 1, (j + 1)
                        * size_x - 1, (i + 1) * size_y + 50 - 1)
                rect = tg.Target(self, bbox, 'yellow')
                tg_list.append(rect)
        return tg_list

    def play(self):
        """ Play the game """

        self.ball.redrawn_ball()

        winner = self.check_winner()
        if winner is not None:
            self.result = winner
            self.show_result()
            return

        self.check_colision()
        self.parent.after(20, self.play)

    def check_colision(self):
        """ Checks if the ball collided with an object """

        ball_bbox = self.ball.get_bbox()

        overlaps_id = self.find_overlapping(
            ball_bbox[0][0], ball_bbox[0][1], ball_bbox[1][0], ball_bbox[1][1])
        overlaps_id = [x for x in overlaps_id if x != self.ball.get_id()]

        if overlaps_id == []:
            return
        if overlaps_id[0] == self.player.get_id():

            player_bbox = self.player.get_bbox()
            middle_play = (player_bbox[1][0] + player_bbox[0][0]) // 2
            ball_center = (ball_bbox[1][0] + ball_bbox[0][0]) // 2

            if ball_center > middle_play:
                self.ball.bounce_left()
            else:
                self.ball.bounce_right()
        else:
            self.target_colision(overlaps_id)

    def target_colision(self, overlapping):
        """ Handles the colision on the target """

        if len(overlapping) == 1:
            for tgt in self.targets:
                if tgt.get_id() == overlapping[0]:
                    self.targets.remove(tgt)
                    break

            self.delete(overlapping[0])
            self.ball.bounce()

    def check_winner(self):
        """ Check if the player win """

        if self.targets == []:
            return True

        ball_bbox = self.ball.get_bbox()
        if ball_bbox[1][1] >= self.canvassize[1]:
            return False

        return None

    def show_result(self):
        """ Shows the result of the game """

        if self.result:
            text = 'Congratulations!'
        else:
            text = 'You Lose!'
        width, height = self.canvassize
        self.create_text(width // 2, height // 2, text=text,
                         fill='white', font=("Arial", 15, "bold"))
