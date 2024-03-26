#!/usr/bin/python3
"""To define an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for eye in range(height):
        for jhay in range(width):
            if grid[eye][jhay] == 1:
                size += 1
                if (jhay > 0 and grid[eye][jhay - 1] == 1):
                    edges += 1
                if (eye > 0 and grid[eye - 1][jhay] == 1):
                    edges += 1
    return size * 4 - edges * 2
