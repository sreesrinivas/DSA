class Solution {
private:
    struct Compare {
        bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
            return ((get<0>(t1) + get<1>(t1)) > (get<0>(t2) + get<1>(t2)));
        }
    };

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> ans;
        
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0) return ans;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, Compare> pq;
        
        for(int i = 0; i < min((int)nums1.size(), k); i++) pq.push(make_tuple(nums1[i], nums2[0], 0));
        
        while(k-- > 0 && !pq.empty()) {
            tuple<int, int, int> top = pq.top();
            ans.push_back(make_pair(get<0>(top), get<1>(top)));
            
            pq.pop();
            if(get<2>(top) + 1 < nums2.size())
                pq.push(make_tuple(get<0>(top), nums2[get<2>(top)+1], get<2>(top)+1));
        }
        return ans;
    }
};
