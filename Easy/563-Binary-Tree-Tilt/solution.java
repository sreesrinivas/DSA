/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;

    public int findTilt(TreeNode root) {
        helper(root);
        return ans;
    }

    // Post-Order DFS helper method: returns total subtree sum 🔀
    public int helper(TreeNode root) {
        // Base Case: Empty subtree sum is 0 🍃
        if (root == null) return 0;

        // Step 1: Bottom-up evaluation of left and right subtree sums 📐
        int left = helper(root.left);
        int right = helper(root.right);

        // Step 2: Accumulate absolute tilt difference for the current node ⚖️
        ans += Math.abs(left - right);

        // Step 3: Return total subtree sum (current node + left + right) to parent
        return root.val + left + right;
    }
}
