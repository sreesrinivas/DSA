class Solution {
    public int numFriendRequests(int[] ages) {
        int res = 0;
        Arrays.sort(ages);
        for (int i = 0; i < ages.length; ++i) {
            int age = ages[i];
            int lower = firstIdx(ages, age/2+7);
            int upper = firstIdx(ages, age);
            res += Math.max(upper-lower-1, 0);
        }
        return res;
    }
    
    private static int firstIdx(int[] ages, int target) {
        int beg = 0;
        int end = ages.length-1;
        while (beg <= end) {
            int mid = beg + (end-beg)/2;
            if (ages[mid] <= target) beg = mid + 1;
            else end = mid - 1;
        }
        return beg;
    }
}
