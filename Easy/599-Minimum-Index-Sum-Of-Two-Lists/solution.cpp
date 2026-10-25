class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mp1;
    priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    vector<string> ret;
    for (int i = 0; i < list1.size(); i++) {
        mp1.insert(pair<string, int>(list1[i], i));
    }

    for (int i = 0; i < list2.size(); i++) {
        int idx = 0;
        auto found = mp1.find(list2[i]);
        if (found == mp1.end()) {
            continue;
        }
        else {
            pq.push(make_pair(found->second + i, list2[i]));
        }
    }
    auto prev = pq.top();
    while (!pq.empty()) {
        if (pq.top().first == prev.first) {
            ret.push_back(pq.top().second);
            prev = pq.top();
            pq.pop();
        }
        else {
            break;
        }
    }
    return ret;
    }
};
