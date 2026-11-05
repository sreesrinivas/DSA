class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] ans = new int[n];
        boolean[] check = new boolean[n];
        Arrays.sort(nums1);
        for(int i=0;i<n;i++){
            int ind = ceil(nums2[i],nums1,n);
            while(ind<n && check[ind]){
                ind++;
            }
            if(ind==n){
                int k=0;
                while(check[k]==true){
                    k++;
                }
                check[k]=true;
                ans[i]=nums1[k];
            }
            else{
                check[ind]=true;
                ans[i]=nums1[ind];
            }
        }
        return ans;
    }
    int ceil(int x,int[] nums,int n){
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x<nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+1;
    }
}
