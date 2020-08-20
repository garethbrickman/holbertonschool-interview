#!/usr/bin/python3

def rain(walls):
    """ Calculates how much water retained """
    if not walls or len(walls) < 1:
        return 0
