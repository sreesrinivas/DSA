class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.empty()) return "Neither";
        int n=queryIP.size();
        int i4=0,i6=0;
        for(char &ch:queryIP){
            if(ch=='.')
            {
                i4=1;
                break;
            }
            else if(ch==':')
            {
                i6=1;
                break;
            }
        }
        string ans;
        int x=0;
        int c=0;
        if(i4==1)
        {
            if(!isdigit(queryIP[n-1]))
            return "Neither";
            queryIP+='.';
            for(int i=0;i<queryIP.size();i++){
                if(queryIP[i]=='.')
                {
                    string s=queryIP.substr(x,i-x);
                    if(s.empty())
                    return "Neither";
                    if(!regex_match(s,regex("[0-9]+")))
                    return "Neither";
                    if(s.size()>1 && s[0]=='0')
                    return "Neither";
                    if(s.size()>3)
                    return "Neither";
                    if(stod(s)>255)
                    return "Neither";
                    x=i+1;
                    c++;
                }
            }
            if(c==4)
            ans="IPv4";
            else
            ans="Neither";
        }
        else
        {
            if(!isdigit(queryIP[n-1]) && !isalpha(queryIP[n-1]))
            return "Neither";
            queryIP+=':';
            for(int i=0;i<queryIP.size();i++){
                if(queryIP[i]==':')
                {
                    c++;
                    string s=queryIP.substr(x,i-x);
                    int l=i-x;
                    x=i+1;
                    if(!regex_match(s,regex("[0-9a-fA-F]+")))
                    return "Neither";
                    if(l>=1 && l<=4){}
                    else
                    {
                        return "Neither";
                    }
                }
            }
            if(c==8)
            ans="IPv6";
            else
            ans="Neither";
        }
        return ans;
    }
};
