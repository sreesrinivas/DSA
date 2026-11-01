class Solution {
public:
//dfs to find the connected components
    void dfs(int curr,vector<vector<int> >&adj,vector<bool>&vis)
    {
        vis[curr]=true;
        for(auto x:adj[curr])
        {
            if(!vis[x])
                dfs(x,adj,vis);
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        vector<int>par(2*n);
        for(int i=0;i<n;i++)
        {
            par[2*i]=i;
            par[2*i+1]=i;
        }
        vector<vector<int> >adj(n);
        int connected_components=0;
        for(int i=0;i<n;i++)
        {
            int u=par[row[2*i]],v=par[row[2*i+1]];
            if(u==v)
                continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               //every dfs call on new vertex corresponds to a new connected component
                connected_components++;
                dfs(i,adj,vis);
            }
            
        }
      
        return n-connected_components;
    }
};
