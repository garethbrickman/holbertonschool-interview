#!/usr/bin/python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """ Rotate 2D Matrix in-place """
    matrix.reverse()
    copy_matrix = matrix.copy()

    for i in range(len(matrix)):
        matrix[i] = [row[i] for row in copy_matrix]
