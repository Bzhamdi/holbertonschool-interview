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
    try:
        bytes([x & 255 for x in data]).decode("UTF-8")
        return True
    except Exception:
        return False
