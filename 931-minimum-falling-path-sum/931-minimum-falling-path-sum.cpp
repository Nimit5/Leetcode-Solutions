class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // out of bound corner case
        if(j<0 || j>=matrix[0].size())
            return 1e9;
        
        // destination reached corner case
        if(i==0) 
            return matrix[0][j];
        
        // subproblem already solved 
        if(dp[i][j]!=-1) 
            return dp[i][j];
        // move up    
        int up=matrix[i][j]+solve(i-1,j,matrix,dp);
        
        // move to left diagonal
        int left_dig=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        
        // move to right diagonal
        int right_dig=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        
        // return minimum of all three
        return dp[i][j]=min(up,min(left_dig,right_dig));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans=1e9;
        
        // checking for all  the entries of last row
        for(int j=0;j<m;j++)
            ans=min(ans,solve(n-1,j,matrix,dp));
        return ans;
    }
};