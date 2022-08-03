#!/usr/bin/python3
'''
Lockboxes finder
Can we unlock the lockboxes ?
'''


def canUnlockAll(boxes):
    '''
    Determines if all the boxes can be opened.
    '''
    listKey = boxes[0]

    for element in boxes[0]:
        if (element < len(boxes)):
            listKey = listKey + boxes[element]

    for idx in range(1, len(boxes)):
        canOpen = False
        for key in listKey:
            if (key == idx):
                canOpen = True

        if (canOpen):
            listKey = listKey + boxes[idx]
        else:
            return False


    return True
