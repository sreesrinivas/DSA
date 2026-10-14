class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(Node* root,int level=0) {
        if(!root) return ans;
        if(ans.size()<=level) ans.push_back({root->val});
        else ans[level].push_back(root->val);
        for(Node* node: root->children) levelOrder(node,level+1);
        return ans;
    }
};
