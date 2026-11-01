from collections import deque
from typing import List

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        start = "".join(str(value) for row in board for value in row)
        goal = "123450"
        neighbors = ((1, 3), (0, 2, 4), (1, 5),
                     (0, 4), (1, 3, 5), (2, 4))
        queue = deque([(start, 0)])
        seen = {start}
        while queue:
            state, steps = queue.popleft()
            if state == goal:
                return steps
            zero = state.index("0")
            for neighbor in neighbors[zero]:
                tiles = list(state)
                tiles[zero], tiles[neighbor] = tiles[neighbor], tiles[zero]
                candidate = "".join(tiles)
                if candidate not in seen:
                    seen.add(candidate)
                    queue.append((candidate, steps + 1))
        return -1
