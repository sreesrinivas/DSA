class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        if not arr:
            return 0
        
        def next_greater_element(arr):
            n = len(arr)
            result = [None]*n
            stack = []
            
            for i in range(n):
                while stack and arr[stack[-1]] < arr[i]:
                    result[arr[stack.pop()]] = arr[i]
                stack.append(i)
            del stack
            return result
        
        n = len(arr)
        arr_sorted = sorted(range(n), key=lambda x: arr[x])
        odd = next_greater_element(arr_sorted)
        
        arr_sorted.sort(key=lambda x: arr[x], reverse=True)
        even = next_greater_element(arr_sorted)
        
        # Index 0, represents path starting with odd jump
        # Index 1, represents path starting with even jump
        dp = [[0, 0] for i in range(n)]
        
        # Last Index is always reachable.
        dp[-1] = [1, 1]
        
        for i in range(n-2, -1, -1):
            
            # If Odd Jump is possible
            if odd[i] is not None:
                dp[i][0] = dp[odd[i]][1]
                
            # If Even Jump is possible
            if even[i] is not None:
                dp[i][1] = dp[even[i]][0]
        
        return sum([i[0] for i in dp])
