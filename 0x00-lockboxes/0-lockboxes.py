#!/usr/bin/python3
'''
Lockboxes finder
Can we unlock the lockboxes ?
'''


def searchKey(boxes, key, boxesOpen):
    '''
    Open all boxes and store all key
    '''
    allKeys = key
    for element in key:
        if (element < len(boxes) and element not in boxesOpen):
            boxesOpen.append(element)
            allKeys = allKeys + searchKey(boxes, boxes[element], boxesOpen)

    return allKeys


def canUnlockAll(boxes):
    '''
    Determines if all the boxes can be opened.
    '''
    boxesOpen = [0]
    listKey = searchKey(boxes, boxes[0], boxesOpen)

    for idx in range(1, len(boxes)):
        if (idx not in listKey):
            return False

    return True
