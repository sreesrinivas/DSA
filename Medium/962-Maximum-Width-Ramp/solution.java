class Solution {
    public int maxWidthRamp(int[] nums) {
       int[][] arr= new int[nums.length][2]; //Creating 2D array..
       for (int i = 0; i < nums.length; i++) {
            arr[i][0] = nums[i];  //stores values to the array
            arr[i][1] = i; //stores original indices
        }
        //sorting the 2D array using custom comparator
        Arrays.sort(arr,(a,b) -> Integer.compare(a[0], b[0])); 

        int minIndex = arr[0][1]; //// Ab tak ka minimum index track karo
        int maxWidth = 0;

        for (int i = 1; i < arr.length; i++) {
            // Calculate the width using the smallest index
            maxWidth = Math.max(maxWidth, arr[i][1] - minIndex);
            //update minimum index
            minIndex = Math.min(minIndex, arr[i][1]);
        }

        return maxWidth;
    }
}
