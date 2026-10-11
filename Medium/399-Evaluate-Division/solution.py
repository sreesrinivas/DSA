class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
         
        def build_graph(equations,values):
            G = collections.defaultdict(list)
            for i in range(len(equations)):
                edge = equations[i]
                weight = values[i]
                source , dest = edge
                G[source].append((dest,weight))
                G[dest].append((source, 1/weight))  
            return G
            
        def dfs(s,e,seen,G,value): 
            if s not in G or e not in G or s in seen:
                return -1 
            if s == e:
                return value 
            seen.append(s)
            for i in range(len(G[s])):
                product = dfs(G[s][i][0],e,seen,G,value * G[s][i][1])  
                if product != -1:
                    return product    
            return -1   
            
        G = build_graph(equations,values)
        
        return [dfs(s,e,[],G,1.0) for s,e in queries]
