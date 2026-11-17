class Solution 
{
    int[] ans;
    public int[] gardenNoAdj(int N, int[][] edges) 
    {
        ans = new int[N];
        
        List<Integer> adj[] = new ArrayList[N];
        for(int i = 0; i < N; i++)
            adj[i] = new ArrayList<>();
        
        for(int[] e : edges)
        {
            adj[e[0]-1].add(e[1]-1);
            adj[e[1]-1].add(e[0]-1);
        }
        
        //Just mark all the colors that have been used by the neighbours
        //and then paint color which is not used by the neigbours.
        //there will always be atleast one unused color.
        for(int u = 0; u < N; u++)
        {
            boolean[] used = new boolean[5];
            
            for(int v : adj[u])
                used[ans[v]] = true;
            
            for(int c = 1; c <= 4; c++)
            {
                if(!used[c])
                {
                    ans[u] = c;
                    break;//not necessary
                }
            }
        }
        
        return ans;
    }
}
