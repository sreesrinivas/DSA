def min_range(border_crossings, towers):
    """
    Returns the minimum range needed for a sensor to cover all border crossings.

    Args:
    border_crossings: A list of the border crossing locations.
    towers: A list of the tower locations.

    Returns:
    The minimum range needed for a sensor to cover all border crossings.
    """

    border_crossings.sort()
    towers.sort()
    res = []
    for crossing in border_crossings:
        min_distance = float("inf")
        for tower in towers:
            print('tower', tower)
            distance = abs(crossing - tower)
            min_distance = min(min_distance, distance)
        res.append(min_distance)
    return max(res)


border_crossings = [1, 2, 3, 4, 6, 10, 12]
towers = [1, 4, 6]
print(min_range(border_crossings, towers))
