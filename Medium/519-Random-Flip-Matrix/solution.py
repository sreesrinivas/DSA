class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.reset()

    def flip(self) -> List[int]:
        return self.a.pop()

    def reset(self) -> None:
        self.a = [[i, j] for j in range(self.m) for i in range(self.n)]
        random.shuffle(self.a)
