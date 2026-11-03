class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans = "", temp = "";
        int k = 0;
        for(int i = 0; i < sentence.size();i++){
            if(sentence[i] != ' ') temp += sentence[i];
            else{
                if(temp[0] == 97 || temp[0] == 101 || temp[0] == 105 || temp[0] == 111 || temp[0] == 117 || temp[0] == 65 || temp[0] == 69 || temp[0] == 73 || temp[0] == 79 || temp[0] == 85){
                    temp += "ma";
                }
                else{
                    temp = temp + temp[0] + "ma";
                    temp = temp.substr(1);
                }
                for(int j = 0; j <= k; j++){
                    temp += "a";
                }
                k++;
                cout<<temp<<endl;
                ans += temp + " ";
                temp = "";
            }
        }
        if(temp[0] == 97 || temp[0] == 101 || temp[0] == 105 || temp[0] == 111 || temp[0] == 117 || temp[0] == 65 || temp[0] == 69 || temp[0] == 73 || temp[0] == 79 || temp[0] == 85){
            temp += "ma";
        }
        else{
            temp = temp + temp[0] + "ma";
            temp = temp.substr(1);
        }
        for(int j = 0; j <= k; j++){
            temp += "a";
        }
        ans += temp;
        return ans;
    }
};
