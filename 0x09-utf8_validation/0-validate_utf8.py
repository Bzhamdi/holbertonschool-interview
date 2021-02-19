#!/usr/bin/python3

"""
method that determines if a given data set
represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
      Char. number range  |        UTF-8 octet sequence
          (hexadecimal)    |              (binary)
    --------------------+----------------------------
    0000 0000-0000 007F | 0xxxxxxx
    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    """
    c = 0
    for x in data:
        if c == 0:
            if (x >> 5) == 0b110:
                c = 1
            elif (x >> 4) == 0b1110:
                c = 2
            elif (x >> 3) == 0b11110:
                c = 3
            elif (x >> 7):
                return False
        else:
            if (x >> 6) != 0b10:
                return False
            c -= 1
    return c == 0
