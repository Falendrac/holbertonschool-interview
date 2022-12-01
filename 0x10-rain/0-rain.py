#!/usr/bin/python3
"""
    Rain interview
"""


def get_max_wall(walls, wall_index, current_wall, direction='left'):
    """
        Find the maximum element on its left or right
        Args:
            walls (list): list of walls
            wall_index (int): index of the current wall
            current_wall (int): current wall
            direction (str): direction of the search
        Returns:
            int: maximum element on its left or right
    """

    walls_length = len(walls)

    if direction == 'left':
        start = 0
        end = wall_index

    else:
        start = wall_index + 1
        end = walls_length

    for index in range(start, end):
        current_wall = max(current_wall, walls[index])

    return current_wall


def rain(walls):
    """
        Rain water
        Args:
            walls (list): list of walls
        Returns:
            int: rain water
    """

    n = len(walls)

    if n == 0:
        return 0

    # To store the maximum water
    # that can be stored
    rainfall = 0

    # For every element of the array
    for wall_index, wall in enumerate(walls):

        # Find the maximum element on its left
        left = get_max_wall(walls, wall_index, wall, 'left')

        # Find the maximum element on its right
        right = get_max_wall(walls, wall_index, wall, 'right')

        # Update the maximum water
        rainfall += (min(left, right) - wall)

    return rainfall
