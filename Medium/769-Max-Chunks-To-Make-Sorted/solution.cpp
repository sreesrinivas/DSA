class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax(n), sufMin(n);

        preMax[0] = arr[0]; 
        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], arr[i]);
        }
        
        sufMin[n-1] = arr[n-1]; 
        for(int i = n-2; i>=0; i--){
            sufMin[i] = min(sufMin[i+1], arr[i]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            int lMax = (i == 0)? -1 : preMax[i - 1];
            int rMin = sufMin[i];

            if(lMax < rMin) count++;
        }

        return count;
    }
};
