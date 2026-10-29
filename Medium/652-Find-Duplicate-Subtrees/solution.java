class Solution {
    public String helper(
        TreeNode root,
        List<TreeNode> ans,
        Map<String, Integer> map
    ) {
        if (root == null) return "N";

        String s = root.val + "," +
                   helper(root.left, ans, map) + "," +
                   helper(root.right, ans, map);

        int count = map.getOrDefault(s, 0);

        if (count == 1) {
            ans.add(root);
        }

        map.put(s, count + 1);

        return s;
    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();

        helper(root, ans, map);

        return ans;
    }
}
