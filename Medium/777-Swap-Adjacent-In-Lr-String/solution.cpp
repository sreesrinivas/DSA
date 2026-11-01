class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while(i < start.size() && j < end.size()) {
            while (i < start.size() && start[i] == 'X')
                i++;
            while (j < end.size() && end[j] == 'X')
                j++;
            if (i < start.size() && j < end.size()) {
                if (start[i] != end[j])
                    return false;
                else if (start[i] == 'L' && i < j)
                    return false;
                else if (start[i] == 'R' && i > j)
                    return false;
                i++;
                j++;
            }
        }
        
        while (i < start.size()) {
            if (start[i] != 'X')
                return false;
            i++;
        }
        
         while (j < end.size()) {
            if (end[j] != 'X')
                return false;
            j++;
        }
        return true;
    }
};
