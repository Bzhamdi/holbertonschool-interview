#!/usr/bin/python3
"""UnlockAll"""


def canUnlockAll(boxes):
    """Lockboxes"""
    open = [0]
    
    for sublist in boxes:
        for item in sublist:
            if boxes.index(sublist)in open:
                open.append(item)
    for sublist in boxes:
        for item in sublist:
            if boxes.index(sublist)in open:
                open.append(item)            
    q = set(open)
    for z in range(1, len(boxes)-1):
        if z not in q:
            return False
    return True
