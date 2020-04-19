#!/usr/bin/python3
# from collections import deque


def canUnlockAll(boxes):
    """Unlock array of boxes of keys with indices"""
    n_boxes = len(boxes) - 1
    unique_key_list = []

    if not boxes[0]:
        return False

    for box in boxes:
        for key in box:
            if key not in unique_key_list and key != 0:
                unique_key_list.append(key)

    n_key_list = len(unique_key_list)

    if n_key_list != n_boxes:
        return False

    if (n_boxes/2*(1+n_boxes)) == (n_key_list/2*(1+n_key_list)):
        return True
    return False
