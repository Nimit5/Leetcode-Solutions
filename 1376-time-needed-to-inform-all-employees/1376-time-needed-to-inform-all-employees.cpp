class Solution {
public:
    int dfs(int node, vector<int>& informTime, vector<int> adj[])
    {
        int val=0;
        for(auto it:adj[node])
            val=max(val,dfs(it,informTime,adj));
        return val+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++)
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        
        return dfs(headID,informTime,adj);  
    }
};