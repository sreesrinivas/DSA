class Solution {
    Map<Integer,Integer> dp = new HashMap<>();
    public int leastOpsExpressTarget(int x, int target) {
        if (dp.containsKey(target)) {
            return dp.get(target);
        }
        if (x > target) {
            dp.put(target, Math.min(target * 2 - 1, (x - target) * 2));
            return dp.get(target);
        }
        int times = 0;
        long sum = x;
        while (sum < target) {
            times++;
            sum *= x;
        }
        int subtract = Integer.MAX_VALUE;
        if (sum - target < target) {
            subtract = leastOpsExpressTarget(x, (int)(sum - target)) + times;
        }
        int add = leastOpsExpressTarget(x, target - (int)(sum / x)) + times - 1;
        dp.put(target, Math.min(subtract, add) + 1);
        return dp.get(target);
    }
}
