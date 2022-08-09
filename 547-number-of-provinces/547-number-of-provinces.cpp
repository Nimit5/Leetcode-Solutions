class Solution {
public:
    int check(vector<bool> &vis)
    {
        for(int i=0;i<vis.size();i++)
        {
            if(!vis[i])
                return i; 
        }
        return -1;
    }
    void dfs(int node, vector<int> adj[], vector<int> &ans, vector<bool> &vis)
    {
        vis[node]=true;
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(!vis[it])
                dfs(it,adj,ans,vis);
        }
    }
    void dfsOfGraph(int V, vector<int> adj[], int &count) {
        vector<bool> vis(V,false);
        vector<int> ans;
        count++;
        dfs(0,adj,ans,vis);
        while(true)
        {
            int pt=check(vis);
            if(pt==-1)
                return;
            else
            {
                count++;
                dfs(pt,adj,ans,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1)
          
                    adj[i].push_back(j);
            }
        }
        int count=0;
        dfsOfGraph(V,adj,count);
        return count;
    }
};