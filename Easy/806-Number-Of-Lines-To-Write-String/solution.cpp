class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int sum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            sum += widths[c];
            
            // If the current character pushes the line over 100 units,
            // it must be written on the start of the next line.
            if(sum > 100) {
                line++;
                sum = widths[c]; 
            }
        }
        
        return {line, sum};
    }
};
