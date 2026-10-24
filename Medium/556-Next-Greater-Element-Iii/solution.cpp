class Solution {
public:
    int nextGreaterElement(int n) {
        string s =  to_string(n);
        int x =  s.size();
        int index = -1;
        for(int i= x-1 ; i>=0 ; i--){
        	if(s[i]<s[i+1]){index = i; break;}
        }
        if(index == -1) return  -1;
    
        // reverse( index +1 , x - 1);
        int i = index + 1 , j = x-1 ;
        while(i<=j) swap(s[i++] , s[j--]);

        // upperbound
        int ii =  upper_bound(s.begin() + index + 1  , s.end() , s[index]) - s.begin();
        swap(s[index], s[ii]);
        // cout<< ii << endl;
        long long p =  stoll(s);
        return p<=INT_MAX ? p : -1;
    }
};
