class Solution(object):
    def findComplement(self, num):
        
        x = len(bin(num)[2:])
        m = int('1'*x,2)
        return m^num
