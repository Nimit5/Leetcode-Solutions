class Solution {
public:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, int &timer, vector<int> adj[], vector<vector<int>>& ans)
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,timer,adj,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {   
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(it);
                    ans.push_back(temp);
                }
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int timer=0;
        vector<int> tin(n,-1),low(n,-1),vis(n,0);
        vector<int> adj[n];
        vector<vector<int>> ans;
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i,-1,vis,tin,low,timer,adj,ans);
        return ans;
    }
};