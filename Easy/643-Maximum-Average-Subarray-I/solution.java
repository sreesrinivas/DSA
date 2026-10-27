class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int i = 0;
        int j = 0;
        double sum = 0;
        double maxAvg = Double.NEGATIVE_INFINITY;

        while (j < nums.length) {
            sum = sum + nums[j];

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                maxAvg = Math.max(maxAvg, sum / k);
                sum = sum - nums[i];

                i++;
                j++;
            }

        }
        return maxAvg;
    }
}
