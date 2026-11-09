class Solution(object):
  def threeSumMulti(self, A, target):

    hash = {}

    res = 0
    MOD = 10**9 + 7

    for i, val in enumerate(A):

      res = (res + hash.get(target - val, 0)) % MOD

      for j in range(i):
        temp = A[j] + val

        hash[temp] = hash.get(temp, 0) + 1
    return res
