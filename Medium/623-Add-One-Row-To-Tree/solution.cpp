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
    void abc(TreeNode* root,int val,int depth,int x){
        if(root==NULL || x>depth-1) return;
        if(x==depth-1){
            TreeNode* a = new TreeNode(val);
            TreeNode* b = new TreeNode(val);
            a->left=root->left;
            b->right=root->right;
            root->left=a;
            root->right=b;
            return;
        }
        abc(root->left,val,depth,x+1);
        abc(root->right,val,depth,x+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* a =  new TreeNode(val);
            a->left=root;
            return a;
        }
        abc(root,val,depth,1);
        return root;
    }
};
