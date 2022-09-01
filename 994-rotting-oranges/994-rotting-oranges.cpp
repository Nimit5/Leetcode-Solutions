class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        
        int m=grid.size(),n=grid[0].size(),countfresh=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)
                    q.push({{i,j},0}),vis[i][j]=1;
                else if(grid[i][j]==1)
                    countfresh++;
        int ans=0,cnt=0;
        int drow[4]={-1,0,0,1};
        int dcol[4]={0,-1,1,0};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            ans=max(t,ans);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
        }
        return cnt==countfresh?ans:-1;
    }
};