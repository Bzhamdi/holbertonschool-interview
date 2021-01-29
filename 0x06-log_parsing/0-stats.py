#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""


import sys

mydict = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}

file_size = 0

try:
    for x, line in enumerate(sys.stdin, 1):
        spline = line.split()
        spline_lenth = len(spline)
        if spline_lenth > 2:
            statuscode = spline[spline_lenth - 2]
            file_size += int(spline[spline_lenth - 1])
            if statuscode in mydict:
                mydict[str(statuscode)] += 1
        if x % 10 == 0:
            print("File size: {}".format(file_size))
            for i in sorted(mydict):
                if mydict[i] > 0:
                    print("{}: {}".format(i, mydict[i]))
except KeyboardInterrupt:
    pass
finally:
    print('File size: {:d}'.format(file_size))
    for key in sorted(mydict.keys()):
        if mydict[key] != 0:
            print("{}: {:d}".format(key, mydict[key]))
