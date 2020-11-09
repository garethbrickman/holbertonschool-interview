#!/usr/bin/python3
""" Making change """


def makeChange(coins, total):
    """ Returns fewest number of coins needed to meet total
    """

    if total <= 0:
        return 0
    else:
        from math import trunc

        coins = sorted(coins, reverse=True)
        coin_dict = {}
        while total is not None:
            for c in coins:
                if total % c == 0:
                    coin_dict[c] = total / c
                    return(int(sum(coin_dict.values())))
                else:
                    coin_dict[c] = trunc(total / float(c))
                    total -= (c * coin_dict[c])
            return -1
