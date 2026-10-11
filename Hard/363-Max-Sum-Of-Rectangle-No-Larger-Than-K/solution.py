def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not matrix:  return 0
        
        res = float('-inf')
        rows, columns = len(matrix), len(matrix[0])
        for i in range(columns):
            sums = [0 for _ in range(rows)]
            for j in range(i, columns):
                for r in range(rows):
                    sums[r] += matrix[r][j]

                # find the largest sum of a subarray which is no more than K
                import bisect
                cum_sum = [0]
                cum, max_sum = 0, float('-inf')
                for item in sums:
                    cum += item
                    left = bisect.bisect_left(cum_sum, cum - k)
                    if left < len(cum_sum):
                        max_sum = max(max_sum, cum - cum_sum[left])
                    bisect.insort(cum_sum, cum)

                res = max(res, max_sum)

        return res
