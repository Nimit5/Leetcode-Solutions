class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]!=1)
            return;
        grid[i][j]=0;
        
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(i==0 || i==row-1 || j==0 || j==col-1)
                    dfs(i,j,grid);
        int ans=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==1)
                    ans++;
        return ans;
    }
};