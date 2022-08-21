class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>& keys, vector<vector<int>>& rooms)
    {
        vis[node]=1;
        for(auto it:rooms[node])
        {
            keys[it]=1;
            if(!vis[it])
            {
                dfs(it,vis,keys,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0),keys(n,0);
        keys[0]=1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && keys[i]!=0)
            {
                dfs(i,vis,keys,rooms);
            }
        }
        for(int i=0;i<n;i++)
            if(keys[i]==0)
                return false;
        return true;
    }
};