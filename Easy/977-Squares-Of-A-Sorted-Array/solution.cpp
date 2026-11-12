class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> s(A.size());
        int l = 0, r = A.size() - 1;
        for (int p = r; p >= 0; p--) {
            s[p] = A[l] * A[l] >= A[r] * A[r] ? A[l] * A[l++] : A[r] * A[r--];
        }
        return s;
    }
};
