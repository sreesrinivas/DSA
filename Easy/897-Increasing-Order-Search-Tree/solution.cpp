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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *iterator = nullptr;
        TreeNode *header = nullptr;
        vector<int> temp;
        Tree(root,temp);
        for(int i = 0; i < temp.size(); i++){
            if(i == 0){
                TreeNode *newnode = new TreeNode();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->val = temp[i];
                header = newnode;
                iterator = newnode;
            }
            else{
                TreeNode *newnode = new TreeNode();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->val = temp[i];
                iterator->right = newnode;
                iterator = iterator->right;
            }
        }
        return header;
    }
    void Tree(TreeNode *root, vector<int> &temp){
        if(root == nullptr) return;
        Tree(root->left,temp);
        temp.push_back(root->val);
        Tree(root->right,temp);
    }
};
