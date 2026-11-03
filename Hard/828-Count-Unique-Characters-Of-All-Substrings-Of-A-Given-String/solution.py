class Solution(object):
    def uniqueLetterString(self, s):
        if s is None:
            raise RuntimeError("Bad input; s cannot be None")
        lastSeen = {}
        retval = 0
        lastStepCount = 0
        for i in range(len(s)):
            lastTwoSeenIndices = lastSeen.get(s[i], None)
            if not lastTwoSeenIndices:
                currentStepCount = lastStepCount + i + 1
                lastSeen[s[i]] = (-1, i)
            else:
                secondLastSeenIndex, lastSeenIndex = lastTwoSeenIndices
                numOfSuffixesWithoutCurrChar = i - 1 - lastSeenIndex
                numOfSuffixesWithJustOneOccurrenceOfCurrChar = \
                    lastSeenIndex - secondLastSeenIndex
                currentStepCount = \
                    lastStepCount + \
                    1 + \
                    numOfSuffixesWithoutCurrChar - \
                    numOfSuffixesWithJustOneOccurrenceOfCurrChar
                lastSeen[s[i]] = (lastSeenIndex, i)
            
            retval += currentStepCount
            lastStepCount = currentStepCount

        return retval
