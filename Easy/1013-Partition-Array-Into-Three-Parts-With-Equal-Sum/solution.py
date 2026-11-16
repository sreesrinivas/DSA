class Solution(object):
    def canThreePartsEqualSum(self, A):
        expected, total, count = sum(A)/3, 0, 0
        for i in A:
        	total += i
        	if total == expected:
        		count += 1
        		total = 0
        return count == 3
