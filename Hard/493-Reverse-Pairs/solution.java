class Solution {
    
    //Divide the array and count reverse pairs
    public static int divide(int[] nums, int low, int high){
        if(low >= high){
            return 0;
        }

        int count = 0;
        int mid = low + (high - low)/2;
        count += divide(nums, low, mid);
        count += divide(nums, mid + 1, high);
        count += countpair(nums, low, high, mid);
        conquer(nums, low, high, mid);

        return count;
    }

    //Merge two sorted halves
    public static void conquer(int[] nums, int low, int high, int mid){
        int[] merged = new int[high - low + 1];

        int left = low;
        int right = mid + 1;
        int k = 0;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                merged[k++] = nums[left++];
            }
            else{
                merged[k++] = nums[right++];
            }
        }

        while(left <= mid){
            merged[k++] = nums[left++];
        }

        while(right <= high){
            merged[k++] = nums[right++];
        }

        for(int i = 0, j = low; i < merged.length; i++, j++){
            nums[j] = merged[i];
        }


    }

    //Count reverse pairs across the two sorted halves
    public static int countpair(int[] nums, int low, int high, int mid){
        int count = 0;
        int right = mid + 1;

        for(int i = low; i <= mid; i++){
            while(right <= high && (long)nums[i] > 2L * nums[right]){
                right++;
               
            }
            count += right -  (mid + 1);
        }
        return count;
    }

    
    public int reversePairs(int[] nums) {
        return divide(nums, 0, nums.length - 1);
        
    }
}
