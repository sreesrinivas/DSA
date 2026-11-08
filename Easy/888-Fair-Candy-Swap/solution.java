class Solution {
    public int[] fairCandySwap(int[] a, int[] b) {
        int asum = 0 , bsum = 0;

        for(int num : a){
            asum += num;
        }

        HashSet<Integer> bobset = new HashSet<>();
        for(int num : b){
            bsum += num;
            bobset.add(num);
        }

        int diff = (bsum - asum)/2;

        for(int x : a){
            int target = x + diff;
            if(bobset.contains(target)){
                return new int[]{x, target};
            }
        }
        return new int[0];
    }
}
