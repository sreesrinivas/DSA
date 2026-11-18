class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int i = 1, j = 0;

        for (int w : weights) {
            i = Math.max(i, w);
            j += w;
        }

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (canFit(mid, weights, days)) j = mid;
            else i = mid + 1;
        }

        return i;
    }

    public boolean canFit(int num, int[] weights, int targetDays) {
        int load = 0, dayCount = 1;

        for (int w : weights) {
            if (load + w > num) {
                dayCount++;
                load = 0;
            }
            load += w;

            if (dayCount > targetDays) return false;
        }

        return true;
    }
}
