class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[], int &count)
    {
        vis[node]=1;
        count++;
        for(auto it:adj[node])
            if(!vis[it])
                dfs(it,vis,adj,count);
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n,0);
        for(auto it : restricted)
            vis[it]=1;
        
        int count=0;
        dfs(0,vis,adj,count);
        return count;
    }
};