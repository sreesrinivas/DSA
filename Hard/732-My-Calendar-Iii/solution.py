class MyCalendarThree:

    def __init__(self):
        self.map = {}
        self.maxi = 0

    def book(self, startTime: int, endTime: int) -> int:
        self.map[startTime] = self.map.get(startTime, 0) + 1
        self.map[endTime] = self.map.get(endTime, 0) - 1

        curr_max = 0

        for time in sorted(self.map):
            curr_max += self.map[time]
            self.maxi = max(self.maxi, curr_max)

        return self.maxi
