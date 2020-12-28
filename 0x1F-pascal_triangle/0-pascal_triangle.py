#!/usr/bin/python3
""" Module for Pascal's triangle """


def pascal_triangle(n):
    """ Returns list of lists of ints representing Pascal’s triangle of n """

    new_list = []

    if len(n) <= 0:
        return new_list
        
