#!/usr/bin/python3
'''
Lockboxes finder
Can we unlock the lockboxes ?
'''


def searchKey(boxes):
    '''
    Open all boxes and store all key
    '''
    boxesOpen = [ boxes[0] ]

    for box in boxesOpen:
        for key in box:
            if key < len(boxes) and boxes[key] not in boxesOpen:
                boxesOpen.append(boxes[key])

    return boxesOpen


def canUnlockAll(boxes):
    '''
    Determines if all the boxes can be opened.
    '''
    boxesOpen = searchKey(boxes)

    return len(boxes) == len(boxesOpen)
