class Solution {

public:

    int smallestRangeI(vector<int>& A, int K) {

        int min_val = A[0], max_val = A[0];

        for (int x : A) {

            min_val = min(min_val, x);

            max_val = max(max_val, x);

        }

        return max(0, max_val - min_val - 2 * K);

    }

};
