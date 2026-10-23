def removeBoxes(self, boxes: List[int]) -> int:
        memo={}
        def dp(l, r, k):
            if l>r: return 0
            if (l,r,k) in memo: return memo[(l,r,k)]
            # while l<r and boxes[l]==boxes[l+1]: #got TLE
            #     l+=1
            #     k+=1
            ans = (k+1)*(k+1) + dp(l+1, r, 0)
            for m in range(l+1, r+1):
                if boxes[m]==boxes[l]:
                    ans = max(ans, dp(l+1, m-1, 0)+dp(m, r, k+1))
            memo[(l,r,k)]=ans
            return ans
        return dp(0, len(boxes)-1, 0)
