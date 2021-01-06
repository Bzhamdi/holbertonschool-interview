#!/usr/bin/python3
"""
minimum_operations
"""


def minOperations(n):
    """
    calculates the fewest number
    of operations needed to result
    in exactly n H characters in the file
    """
    h = 1
    prev_h = h
    i = 0
    if type(n) is not int:
        return 0
    if n <= 0:
        return 0
    while h < n:
        if n % h == 0:
            if h != 1:
                prev_h = h
            h *= 2
            i += 2
        else:
            h += prev_h
            i += 1
    return i
