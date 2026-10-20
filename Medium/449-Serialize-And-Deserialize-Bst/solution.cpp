class Codec {
    void mySerial(TreeNode* root, string &s) {
        if (root == nullptr) return ;
        s += to_string(root->val) + " ";
        mySerial(root->left, s);
        mySerial(root->right, s);
    }
    TreeNode* myDeserial(queue<int> &q, int lo, int hi) {
        if (q.empty()) return nullptr;
        int val = q.front();
        if (val < lo || val > hi) return nullptr;
        TreeNode *root = new TreeNode(val);
        q.pop();
        root->left  = myDeserial(q, lo, val);
        root->right = myDeserial(q, val, hi);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        mySerial(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        queue<int> q;
        string s;
        while (iss >> s) q.push(stoi(s));
        return myDeserial(q, INT_MIN, INT_MAX);
    }
};
