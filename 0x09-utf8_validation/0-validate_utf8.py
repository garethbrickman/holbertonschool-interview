#!/usr/bin/python3
""" determines if a given data set represents a valid UTF-8 encoding """


def validUTF8(data):
    # checks if most significant byte is 1
    mask1 = 1 << 7
    # checks if second most significant byte is 0
    mask2 = 1 << 6
    # keeps track of how many 1s before 0 occurs
    n_bytes = 0

    if not data or len(data) == 0:
        return True

    for num in data:
        mask = 1 << 7
        if n_bytes == 0:
            while (mask & num):
                n_bytes += 1
                mask = mask >> 1

            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:

            if not (num & mask1 and not (num & mask2)):
                return False
        n_bytes -= 1

    if n_bytes:
        return False
    else:
        return True
