class Solution {
    public int preimageSizeFZF(int k) {
        long left = first(k);
        long right = first((long) k + 1);
        return (int) (right - left);
    }

    private long first(long k) {
        long left = 0, right = 5 * (k + 1);

        while (left < right) {

            long mid = left + (right - left) / 2;

            if (count(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    private long count(long n) {
        long zeros = 0;

        while (n > 0) {
            n /= 5;
            zeros += n;
        }

        return zeros;
    }
}
