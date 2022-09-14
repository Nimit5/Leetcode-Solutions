class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>& stones, vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,vis,stones,adj);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int connected=0;
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                connected++;
                dfs(i,vis,stones,adj);
            }
        }
        return n-connected;
    }
};