#!/usr/bin/python3
""" Module for peak list rainfall problem """


def rain(walls):
    """ Calculates how much water retained """

    if not walls or len(walls) <= 2:
        return 0

    list_len = len(walls)
    total = 0
    for idx, elem in enumerate(walls):
        next = idx + 1
        if elem <= next:
            if next == 0:
                total += 1
            else:
                total += elem
    return total
