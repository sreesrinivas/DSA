class UnionFind {
    vector<int> parent, rank; 
public: 
    UnionFind(int n) {
        parent.resize(n); 
        iota(parent.begin(), parent.end(), 0); 
        rank.resize(n); 
        fill(rank.begin(), rank.end(), 1); 
    }
    
    int find(int p) {
        if (p != parent[p]) 
            parent[p] = find(parent[p]); 
        return parent[p]; 
    }
    
    bool connect(int p, int q) {
        int prt = find(p), qrt = find(q); 
        if (prt == qrt) return false; 
        if (rank[prt] > rank[qrt]) swap(prt, qrt); 
        parent[prt] = qrt; 
        rank[qrt] += rank[prt]; 
        return true; 
    }
}; 


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<int> parent(n, 0), cand0, cand1, cand2; 
        bool mult = false, cycle = false; 
        UnionFind *uf = new UnionFind(n); 
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1]; 
            if (parent[v-1]) {
                mult = true; 
                cand0 = {parent[v-1], v}; 
                cand1 = {u, v}; 
            } else {
                parent[v-1] = u; 
                if (!uf->connect(u-1, v-1)) {
                    cycle = true; 
                    cand2 = {u, v}; 
                }
            }
        }
        return mult && cycle ? cand0 : mult ? cand1 : cand2; 
    }
};
