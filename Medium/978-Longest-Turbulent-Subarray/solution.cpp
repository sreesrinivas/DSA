class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        
        int i,ans=1,len=1,n=a.size();
        
        
        for(i=0;i<n-1;i++){
            
            if( ( (i&1)  and a[i]<a[i+1] ) or ( (i%2==0) and a[i]>a[i+1] ) ){
                len++;
            }
            else{
                ans = max(ans, len);
                len = 1;
            }
        }
        
        ans = max(ans,len);
        len=1;
        for(i=0;i<n-1;i++){
            
            if( ((i&1)  and a[i]>a[i+1]) or ((i%2==0) and a[i]<a[i+1]) ){
                len++;
            }
            else{
                ans = max(ans, len);
                len = 1;
            }
        }
        
        ans = max(ans,len);
        
        return ans;
    }
};
