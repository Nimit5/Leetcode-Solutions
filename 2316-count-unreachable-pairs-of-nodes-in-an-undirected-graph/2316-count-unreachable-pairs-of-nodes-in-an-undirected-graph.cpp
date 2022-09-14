class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[], int &count)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                 count++;
                dfs(it,vis,adj,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long>connected;
        vector<int> adj[n];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int count=1;
                dfs(i,vis,adj,count);
                connected.push_back(count);
            }
        }
        long long ans=0;
        for(auto it:connected)
        { 
            //cout<<it<<" ";
            ans+=it*(n-it);
        }
        return ans/2;
    }
};