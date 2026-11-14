class Solution {
public:
    string ans = "";
    void dfs(TreeNode* root, string curr = "") {
        if (!root) return;
        curr.insert(curr.begin(), 'a' + root->val);
        if (!root->left && !root->right) {
            if (ans.empty())
                ans = curr;
            else 
                ans = min(ans, curr);
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
        curr.erase(curr.begin());
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
