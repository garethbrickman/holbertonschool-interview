#!/usr/bin/python3


def canUnlockAll(boxes):
    """Unlock array of boxes of keys with indices"""
    size = len(boxes)
    checker = {}
    index = 0

    for keys in boxes:
        if len(keys) == 0 or index == 0:
            checker[index] = -1  # -1 means box is empty
        for key in keys:
                if key < size and key != index:
                    checker[key] = key
        if len(checker) == size:
            return True
        index += 1
    return False
