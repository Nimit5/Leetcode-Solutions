class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row>0 && grid[row-1][col]=='1' && !vis[row-1][col])
            {
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(row<n-1 && grid[row+1][col]=='1' && !vis[row+1][col])
            {
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(col>0 && grid[row][col-1]=='1' && !vis[row][col-1])
            {
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
            if(col<m-1 &&grid[row][col+1]=='1' && !vis[row][col+1])
            {
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return count;
    }
};