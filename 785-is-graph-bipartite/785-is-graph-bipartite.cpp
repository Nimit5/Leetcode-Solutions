class Solution {
public:
    bool bipartiteDfs(int node, vector<vector<int>>& graph, vector<int>&color)
    {
        if(color[node]==-1)
            color[node]=1;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!bipartiteDfs(it,graph,color))
                    return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // 2D graph vector is nothing but an adjacency list
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
                if(!bipartiteDfs(i,graph,color))
                    return false;
        }
        return true;
    }
};
