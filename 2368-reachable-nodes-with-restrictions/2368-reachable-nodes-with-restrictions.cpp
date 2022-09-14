class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[], int &count, unordered_map<int,int>&mp)
    {
        vis[node]=1;
        count++;
        for(auto it:adj[node])
        {
            if(!vis[it] and mp.find(it)==mp.end())
            {
                dfs(it,vis,adj,count,mp);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_map<int,int>mp;
        for(auto it : restricted)
            mp[it]=1;
        
        vector<int>vis(n,0);
        int count=0;
        dfs(0,vis,adj,count,mp);
        return count;
    }
};