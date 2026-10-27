/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void preorder(TreeNode* root, int r, int c, int height, vector<vector<string>>& ans){
        if(!root) return;

        if(root->left){
            int row = r+1 , col = c - pow(2, height-r-1);
            ans[row][col] = to_string(root->left->val);
            preorder(root->left,row, col, height, ans);
        }

        if(root->right){
            int row = r+1 , col = c + pow(2, height-r-1);
            ans[row][col] = to_string(root->right->val);
            preorder(root->right,row, col, height, ans);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root), n = pow(2,height)-1;
        vector<vector<string>> ans(height, vector<string>(n, ""));
        ans[0][(n-1)/2] += to_string(root->val);
        preorder(root,0,(n-1)/2, height-1, ans);

        return ans;
    }
};
