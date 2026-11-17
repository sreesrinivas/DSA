class Solution {

    private int help(int i, int target, int[] stones) {

        // Base case
        if (i == 0) {
            if (stones[0] <= target)
                return stones[0];

            return 0;
        }

        // Do not take the current stone
        int notTake = help(i - 1, target, stones);

        // Take the current stone
        int take = 0;

        if (stones[i] <= target) {
            take = stones[i]
                 + help(i - 1, target - stones[i], stones);
        }

        return Math.max(take, notTake);
    }

    public int lastStoneWeightII(int[] stones) {

        int total = 0;

        for (int stone : stones) {
            total += stone;
        }

        int target = total / 2;

        int s1 = help(stones.length - 1, target, stones);

        return total - 2 * s1;
    }
}
