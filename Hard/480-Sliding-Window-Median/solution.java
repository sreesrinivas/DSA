import java.util.*;

class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        List<Double> res = new ArrayList<>();

        // store first half [0 ... n/2]
        TreeSet<int[]> maxset = new TreeSet<>((a, b) -> {
            if (a[0] != b[0]) return b[0] - a[0];
            return b[1] - a[1];
        });

        // store second half [n/2 .... n]
        TreeSet<int[]> minset = new TreeSet<>((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        for (int i = 0; i < k; i++) {
            minset.add(new int[]{nums[i], i});
        }

        for (int i = 0; i < k / 2; i++) {
            int[] it = minset.first();
            maxset.add(it);
            minset.remove(it);
        }

        double median;
        if (k % 2 == 1)
            median = minset.first()[0];
        else
            median = (1.0 * maxset.first()[0] + 1.0 * minset.first()[0]) / 2.0;

        res.add(median);

        int r = k, l = 0;

        while (r < nums.length) {

            int[] add = new int[]{nums[r], r};
            int[] remove = new int[]{nums[l], l};
            int f = 1;

            if (maxset.contains(remove)) {
                maxset.remove(remove);
                f--;
            } else {
                minset.remove(remove);
            }

            if (f == 1) {
                maxset.add(add);
                int[] it = maxset.first();
                minset.add(it);
                maxset.remove(it);
            } else {
                minset.add(add);
                int[] it = minset.first();
                maxset.add(it);
                minset.remove(it);
            }

            if (k % 2 == 1)
                median = minset.first()[0];
            else
                median = (1.0 * maxset.first()[0] + 1.0 * minset.first()[0]) / 2.0;

            res.add(median);

            r++;
            l++;
        }

        double[] ans = new double[res.size()];
        for (int i = 0; i < res.size(); i++) ans[i] = res.get(i);
        
        return ans;
    }
}
