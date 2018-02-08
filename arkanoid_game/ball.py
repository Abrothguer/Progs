#!/usr/bin/python3

""" Holds the ball object and it's elements """


class Ball(object):
    """ Implements the ball object """

    def __init__(self, parent, radius, canvassize):

        self.parent = parent
        self.radius = radius
        self.bbox = ((canvassize[0] // 2 - radius, canvassize[1] // 2 - radius),
                     (canvassize[0] // 2 + radius, canvassize[1] // 2 + radius))
        self.canvassize = canvassize

        self.ball_id = self.parent.create_oval(self.bbox, fill='red', outline='white', tag='ball')

        self.speed_x = 2
        self.speed_y = 2

    def redrawn_ball(self):
        """ Redraws the ball on the canvas """

        upper_x = self.bbox[0][0] + self.speed_x
        upper_y = self.bbox[0][1] + self.speed_y
        lower_x = self.bbox[1][0] + self.speed_x
        lower_y = self.bbox[1][1] + self.speed_y

        if upper_x <= 0 or lower_x >= self.canvassize[0]:
            self.speed_x *= -1
        if upper_y <= 0 or lower_y >= self.canvassize[1]:
            self.speed_y *= -1

        self.parent.delete('ball')
        self.bbox = ((upper_x, upper_y), (lower_x, lower_y))

        self.ball_id = self.parent.create_oval(self.bbox, fill='red', outline='white', tag='ball')

    def get_bbox(self):
        """ Returns the ball bbox """

        return self.bbox

    def get_id(self):
        """ Returns the ball id """

        return self.ball_id

    def bounce_left(self):
        """ Bounces left """

        self.speed_x = abs(self.speed_x)
        self.speed_y *= -1

    def bounce_right(self):
        """ Bounces right """

        self.speed_x = -abs(self.speed_x)
        self.speed_y *= -1

    def bounce(self):
        """ Just bounces """

        self.speed_y *= -1
