#!/usr/bin/python3
"""
Calculates min operations
"""


def minOperations(n):
    """ Returns an int or 0 if impossible """

    def minop(n, x=1, cp=1, acc=0):
        if (n == 1 or n < 0):
            return 0
        if (x == n):
            return acc + 1
        if (x > n or acc > n):
            return -1

        #option copy paste
        y = minop(n, x*2, x, acc+2)

        #option paste
        z = minop(n, x+cp, cp, acc+1)

        if (y != -1 and y <= z):
            return y
        return z

    return minop(n, x=1, cp=1, acc=0)
