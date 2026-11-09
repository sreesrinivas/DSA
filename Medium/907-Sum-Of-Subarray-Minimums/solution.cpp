class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), ans = 0, MOD = 1e9 + 7;
        vector<int> NSE(n,-1), PSE(n,-1); //Next smaller element, previous smaller element

        //Populate NSE
        stack<int> s; //Stack of indexes of Monotonically increasing elements (Standard Problem)
        for(int i = 0;i<n;i++){
            if(!s.empty()){
                while(!s.empty() && arr[s.top()]>arr[i]){
                    NSE[s.top()] = i;
                    s.pop();
                }
            }
            if(!s.empty()){
                PSE[i] = s.top();
            }
            s.push(i);
        }

        //Commenting this but initially for clarity I populated this then decided to merge this with the above loop itself

        // //Populate PSE
        // stack<int> p; //Again, stack of Monotonically increasing elements seen so far
        // for(int i = 0;i<n;i++){
        //     while(!p.empty() && arr[p.top()]>arr[i]){
        //         p.pop();
        //     }
        //     if(!p.empty()){
        //         PSE[i] = p.top();
        //     }
        //     p.push(i);
        // }

        for(int i = 0;i<n;i++){
            long long L = PSE[i] == -1? i+1: i - PSE[i];
            long long R = NSE[i] == -1? n -i: NSE[i] - i;
            ans+=(L*R*arr[i]%MOD);
            ans%=MOD;
        }

        return ans;

    }
};
