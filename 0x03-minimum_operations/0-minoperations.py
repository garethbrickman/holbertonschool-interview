#!/usr/bin/python3
"""
Calculates min operations
"""

from sys import setrecursionlimit

setrecursionlimit(10**6)

def minOperations(n):
    """ Returns an int or 0 if impossible """

    count = 0
    inc = 2

    if type(n) is not int or n < 2:
        return 0

    while inc <= n:
        if n % inc == 0:
            count += 1
            n /= inc
        else:
            count += 1
    return count
