class Solution(object):
    def nthUglyNumber(self, n):
        &quot;&quot;&quot;
        :type n: int
        :rtype: int
        &quot;&quot;&quot;
        if n == 1: return 1
        p1, p2, p3 = 0, 0, 0 #pointers in the following list
        
        q = [0] * n
        q[0] = 1
        
        for i in range(1, n):
            t1, t2, t3 = q[p1] * 2, q[p2] * 3, q[p3] * 5
            q[i] = min(t1, t2, t3)
            if q[i] == t1: p1 += 1
            if q[i] == t2: p2 += 1
            if q[i] == t3: p3 += 1
            
        return q[-1]
