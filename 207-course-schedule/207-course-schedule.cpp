class Solution {
public:
    bool checkDfs(int node, vector<int> &vis, vector<int> &dfs, vector<int> adj[])
    {
        vis[node]=1;
        dfs[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {    
               if(checkDfs(it,vis,dfs,adj))
                    return true;
            }
            else if(dfs[it])
                return true;
        }
        dfs[node]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses,0),dfs(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(checkDfs(i,vis,dfs,adj))
                    return false;
            }
        }
        return true;
    }
};