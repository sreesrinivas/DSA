class Solution {
public:
    int countSegments(string s) {
      if(s.empty()){
        return 0;
      }  int cnt=0;bool m=false;
      for(char ch:s){
        if(ch!=' '){
            m=true;
            continue;
        }
        if(ch==' ' && m){
            cnt++;
            m=false;
        }
      }
      if(m){
        cnt++;
      }
      return cnt;
    }
};
