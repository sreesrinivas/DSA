class Solution {
    public int arrayNesting(int[] nums) {
        boolean visited[] = new boolean[nums.length];
		int result = 0;
		for (int i = 0; i < nums.length; i++) {
			if (!visited[i]) {
				int start = i;
				int count = 0;
				while (visited[start] == false) {
					count++;
					visited[start] = true;
					start = nums[start];
				}
				if (result < count) {
					result = count;
				}
			}
		}
		return result;
    }
}
