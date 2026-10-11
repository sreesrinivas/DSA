class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;
        int res=10,mutil=9;
        n=n>10?10:n;
        for(int i=1;i<n;i++){
            mutil*=10-i;
            res+=mutil;
        }
        return res;
    }
};
