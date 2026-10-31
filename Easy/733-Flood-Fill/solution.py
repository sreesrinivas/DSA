from collections import deque

class Solution:
    def floodFill(self, image: list[list[int]], sr: int, sc: int, color: int) -> list[list[int]]:
        # If the original color is already the new color, no changes are needed.
        if image[sr][sc] == color:
            return image

        q = deque()
        q.append([sr, sc])

        # Create an independent copy of the image.
        image_copy = [row[:] for row in image]
        original_color = image_copy[sr][sc]

        # Immediately change the starting pixel's color.
        image_copy[sr][sc] = color

        # Explore all connected pixels having the original color.
        while q:
            i, j = q.popleft()

            # Check the four neighbours: down, right, up, and left.
            for x, y in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                dx, dy = i + x, j + y

                # If the neighbour is valid and has the original color,
                # change its color and add it to the queue.
                if (
                    0 <= dx < len(image) and
                    0 <= dy < len(image[0]) and
                    image_copy[dx][dy] == original_color
                ):
                    image_copy[dx][dy] = color
                    q.append([dx, dy])

        return image_copy
