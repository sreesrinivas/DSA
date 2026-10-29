class Solution(object):
    def flipLights(self, n, presses):
        n = min(n, 3)
        if presses == 0:
            return 1
        elif presses == 1:
            return [2, 3, 4][n - 1]
        elif presses == 2:
            return [2, 4, 7][n - 1]
        else:
            return [2, 4, 8][n - 1]
