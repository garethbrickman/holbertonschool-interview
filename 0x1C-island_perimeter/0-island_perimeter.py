#!/usr/bin/python3
""" Module for island perimeter problem """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """

    if not grid or len(grid) <= 2:
        return 0

    # list_len = len(grid)
    # total = 0
    # for idx, elem in enumerate(grid):
    #     next = idx + 1
    #     if elem <= next:
    #         if next == 0:
    #             total += 1
    #         else:
    #             total += elem
    # return total
