#!/usr/bin/python3
'''
Lockboxes finder
Can we unlock the lockboxes ?
'''


def searchKey(boxes):
    '''
    Open all boxes and store all key
    '''
    boxesOpen = [0]

    for box in boxesOpen:
        for key in boxes[box]:
            if key < len(boxes) and key not in boxesOpen:
                boxesOpen.append(key)

    return boxesOpen


def canUnlockAll(boxes):
    '''
    Determines if all the boxes can be opened.
    '''
    boxesOpen = searchKey(boxes)

    return len(boxes) == len(boxesOpen)
