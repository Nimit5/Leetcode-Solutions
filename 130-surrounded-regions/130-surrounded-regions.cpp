// DFS on Boundary 

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return;
        if(grid[i][j]!='O')
            return;
        
        grid[i][j]='P';
        
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
    }
    void solve(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(i==0 || i==row-1 || j==0 || j==col-1)
                    dfs(i,j,grid);

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]=='O')
                    grid[i][j]='X';
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]=='P')
                    grid[i][j]='O';
    }
};