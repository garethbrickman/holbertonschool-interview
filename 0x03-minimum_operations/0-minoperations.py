#!/usr/bin/python3
"""
Calculates min operations
"""


def minOperations(n):
    """ Returns an int or 0 if impossible """

    count = 0
    inc = 2

    while inc <= n:
        if n % inc == 0:
            count += 1
            n /= inc
        else:
            count += 1
    return count
