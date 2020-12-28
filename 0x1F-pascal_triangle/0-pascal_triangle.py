#!/usr/bin/python3
""" Module for Pascal's triangle """


def pascal_triangle(n):
    """ Returns list of lists of ints representing Pascal’s triangle of n """

    if n <= 0:
        return []

    pascal = [[1]]
    if n == 1:
        return pascal

    for i in range(1, n):
        left = -1
        right = 0
        in_pas = []
        for j in range(i+1):
            num = 0
            if left > -1:
                num += pascal[i - 1][left]
            if right < i:
                num += pascal[i - 1][right]
            left += 1
            right += 1
            in_pas.append(num)
        pascal.append(in_pas)
    return pascal
