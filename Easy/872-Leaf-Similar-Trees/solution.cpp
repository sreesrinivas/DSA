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

 void leaf(TreeNode* root,vector<int>&leaves){

    if(root==NULL)return;   //iska matlab hai agar root null pr aa gyi to peeche chali jaye jaha se aayi hai

    if(root->left==NULL && root->right==NULL){ //iska matlab hai humari leaf node aa gyi

        leaves.push_back(root->val); //ab hum usse store kr rhe hai vector me and than return karke wapas bhej rhe hai 

        return;
    }

    leaf(root->left,leaves); //ab hum function ko firse call kr rhe hai but with the new root
    leaf(root->right,leaves); //ab hum function ko firse call kr rhe hai but with the new root
 }

 //iss question me mene ek leaf naam ka function bnaya hai jiske through me apne trees ki leaves ki value ek vector me store kr rhi hu and than unn vectors ko compare kr rhi hu

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int>leaves1,leaves2;  //do vectors banaye trees ki leaves ko store krne ke liye

        leaf(root1,leaves1); //first tree ke liye function ko call kiya
        leaf(root2,leaves2); //second tree ke liye function ko call kiya

        return leaves1==leaves2;  //compare kra dono vectors ko      
    }
};
