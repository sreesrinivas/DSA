class Solution {
public:
    int maximumSwap(int num)
    {
        auto s = std::to_string(num);
        for(int i = 0; i < s.size(); ++i){
            auto p = std::max_element(s.rbegin(), s.rend() - i);
            if(s[i] != *p){
                std::swap(s[i], *p);
                break;
            }
        }
        return std::stoi(s);
    }
};
