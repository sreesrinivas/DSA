class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ioc; // vector for storing the indexed of c present in s
        int n=s.length();
        
        vector<int>ans(n); // answer vector
        
        for(int i=0;i<n;++i){
            if(s[i]==c) 
                ioc.push_back(i);
        }
        
        int m=ioc.size(); // size of ioc vector
        int left=0,right=0;
        
        for(int i=0;i<n;++i){
            
            // if current index has crossed ioc[right] then,
            // we need to make the current left to right and 
            // increment current right for pointing to next index of ioc vector ( if exists )
            if(i>ioc[right]){
                left=right;
                if(right<m-1)
                    ++right;
            }
                        
            // difference = min(abs(right nearest 'c' - curr index),abs(left nearest 'c' - curr index))
            ans[i]=min(abs(ioc[right]-i),abs(ioc[left]-i)); 

        }
        
        return ans;
    }
};
