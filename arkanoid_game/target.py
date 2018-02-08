#!/usr/bin/python3

""" Holds the target object and its methods """


class Target(object):
    """ Implements the target object """

    def __init__(self, parent, bbox, color):

        self.parent = parent
        self.bbox = bbox
        self.target_id = parent.create_rectangle(bbox, fill=color, outline='black')

    def get_id(self):
        """ Returns the id of the target """

        return self.target_id

    def get_bbox(self):
        """ Return the bbox of the target """

        return self.bbox
