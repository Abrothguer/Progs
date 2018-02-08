#!/usr/bin/python3

""" Holds the player class and it's methods """


class Player(object):
    """ Implements the player """

    def __init__(self, parent):

        self.parent = parent
        self.coords = ((50, 450), (130, 460))
        self.x_length = 60
        self.tag = 'player'
        self.player_id = parent.create_rectangle(
            self.coords, fill='green', outline='white', tag='player')

    def move_player(self, event):
        """ Moves the player """

        delta_x = self.coords[0][0] - self.coords[1][0]

        if event.x > delta_x:
            self.parent.delete('player')

            half = self.x_length // 2
            coords = ((event.x - half, self.coords[0][1]), (event.x + half, self.coords[1][1]))

            self.player_id = self.parent.create_rectangle(
                coords, fill='green', outline='white', tag='player')
            self.coords = coords

    def get_id(self):
        """ Returns the id of the player in the canvas """

        return self.player_id

    def get_bbox(self):
        """ Returns the bbox of the player """

        return self.coords
