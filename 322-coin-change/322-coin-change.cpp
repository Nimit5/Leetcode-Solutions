class Solution {
public:
    int solve(int i, int x, vector<int> &num,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(x%num[i]==0)
                return x/num[i];
            else 
                return 1e9;
        }
        if(dp[i][x]!=-1) return dp[i][x];
        int nottake=solve(i-1,x,num,dp);
        int take=INT_MAX;
        if(num[i]<=x)
            take=1+solve(i,x-num[i],num,dp);
        return dp[i][x]=min(nottake,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp); 
        return ans!=1e9?ans:-1;
    }
};