class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(n==0)
            return -1;
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int x=node.first,y=node.second;
            if(x==n-1 && y==n-1)
                return grid[x][y];
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(i!=0 || j!=0)
                    {
                        int nx=x+i;
                        int ny=y+j;
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0)
                        {
                            q.push({nx,ny});
                            grid[nx][ny]=grid[x][y]+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};