class Solution {
public:
    int solve(int i, int j1, int j2, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)return -1e8;
        
        if(i==grid.size()-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) 
            return dp[i][j1][j2];
        int ans=INT_MIN;
        for(int d1=-1;d1<=1;d1++)
        {
            for(int d2=-1;d2<=1;d2++)
            {
                if(j1==j2)
                    ans = max(ans,grid[i][j1]+solve(i+1,j1+d1,j2+d2,m,grid,dp));
                else
                    ans = max(ans,grid[i][j1]+grid[i][j2]+solve(i+1,j1+d1,j2+d2,m,grid,dp));
            }
        }
        return dp[i][j1][j2]=ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int> > > dp (n,vector<vector<int> >(m,vector <int>(m,-1)));
        return solve(0,0,m-1,m,grid,dp); 
    }
};