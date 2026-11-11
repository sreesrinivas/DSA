class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto email : emails){

            string ln = "";
           
            string dn = "";
           
            int i=0; 
            while(email[i] != '@' && email[i] != '+'){
                if(email[i] != '.') {
                    ln += email[i];
                }
                i++;
            }
            while(email[i] != '@'){
                i++;
            }
           // int n = email.size();
            dn = email.substr(i+1);

                  st.insert(ln +"@"+ dn);
            
            

        }
        return st.size();
    }
};
