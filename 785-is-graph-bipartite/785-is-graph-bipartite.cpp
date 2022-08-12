class Solution {
public:
    bool bipartiteBfs(int i, vector<vector<int>>& graph, vector<int>&color)
    {
        queue<int> q;
        color[i]=1;
        q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    q.push(it);
                    color[it]=1-color[node];
                }
                else if(color[it]==color[node])
                    return false;
            }
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
                if(!bipartiteBfs(i,graph,color))
                    return false;
        }
        return true;
    }
};