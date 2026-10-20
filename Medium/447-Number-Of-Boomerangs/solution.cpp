class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size(), booms = 0;
        unordered_map<int, int> distances;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distances[distance(points[i], points[j])]++;
            }
            for (auto& p : distances) {
                booms += p.second * (p.second - 1);
            }
            distances.clear();
        }
        return booms;
    }
private:
    int distance(pair<int, int>& p, pair<int, int>& q) {
        return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
    }
};
