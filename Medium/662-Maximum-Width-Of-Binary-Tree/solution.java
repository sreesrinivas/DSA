class Solution {  
    public record Pair(TreeNode node, int val) {
    }
    public int widthOfBinaryTree(TreeNode root) {
        int maxi = 0;
        if (root == null)
            return maxi;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 1));
        while (!q.isEmpty()) {
            int n = q.size();
            int minIdx = 0;
            int maxIdx = 0;
            
            for (int i = 0; i < n; i++) {
                Pair p = q.poll();
                TreeNode node = p.node;
                int val = p.val;

                if(i == 0) minIdx = val;  // Left Most Value in a level
                if(i == n-1) maxIdx = val;  // Right Most Value in a level

                if (node.left != null) 
                    q.offer(new Pair(node.left, (val - minIdx) * 2 + 1));
                if (node.right != null)
                    q.offer(new Pair(node.right, (val - minIdx) * 2 + 2));
            }

            maxi = Math.max(maxi, maxIdx - minIdx + 1);
        }
        return maxi;
    }
}
