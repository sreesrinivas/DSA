class Solution {
    public int numComponents(ListNode head, int[] nums) {
        boolean[] arr = new boolean[10_001];
        for(int num : nums) arr[num] = true;

        int res = 0;
        ListNode ptr = head;
        while(ptr != null) {
            if(!arr[ptr.val]) ptr = ptr.next;
            else {
                while(ptr != null && arr[ptr.val]) {
                    ptr = ptr.next;
                }
                res++;
            }
        }

        return res;
    }
}
