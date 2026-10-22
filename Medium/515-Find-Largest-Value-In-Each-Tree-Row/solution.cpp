class Solution {
public:
    void dfs(TreeNode* root,vector<int>& ans,int depth){
        if(root==NULL) return;
        if(depth==ans.size()) ans.push_back(root->val);
        ans[depth]=max(ans[depth],root->val);
        dfs(root->left,ans,depth+1);
        dfs(root->right,ans,depth+1);
        return;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);
        return ans;
    }
};
