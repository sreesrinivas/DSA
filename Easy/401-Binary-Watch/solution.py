class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        if turnedOn == 0:
            result = ["0:00"]
        else:
            result = []
            for hh, bch in enumerate(map(int.bit_count, range(12))):
                if bch == turnedOn:
                    result.append(f"{hh}:00")
                else:
                    bdiff = turnedOn - bch
                    for mm, bcm in enumerate(map(int.bit_count, range(1, 60)), 1):
                        if bcm == bdiff:
                            result.append(f"{hh}:{mm:02d}")
        return result
