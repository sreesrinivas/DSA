class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();

        // rMin[i] = minimum element from i ... n-1
        vector<int> rMin(n);
        rMin[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i--)
            rMin[i] = min(rMin[i + 1], arr[i]);

        int leftMax = arr[0];
        int chunks = 0;

        // Try every possible split.
        for(int i = 0; i < n - 1; i++)
        {
            leftMax = max(leftMax, arr[i]);

            // Every element on the left is <= every element on the right.
            if(leftMax <= rMin[i + 1])
                chunks++;
        }

        // Last chunk.
        return chunks + 1;
    }
};
