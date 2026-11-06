class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int n = image[0].length;
        int[][] arr = new int[n][n];

        // Step 1: Flip each row
        for (int i = 0; i < n; i++) {
            int k = n - 1;

            for (int j = 0; j < n; j++) {
                arr[i][j] = image[i][k];
                k--;
            }
        }

        // Step 2: Invert each element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = 1;
                }
            }
        }

        return arr;
    }
}
