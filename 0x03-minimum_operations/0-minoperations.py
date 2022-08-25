#!/usr/bin/python3
'''
Interview we search the minimal operations
'''


def minOperations(n):
    '''
    calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    '''
    if type(n) is not int or n <= 1:
        return 0

    coef = 2
    result = 0

    while coef <= n:
        if n % coef == 0:
            n = n / coef
            result += coef
        else:
            coef += 1

    return result
