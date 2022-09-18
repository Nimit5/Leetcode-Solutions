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
        if(dp[i][x]!=-1) 
            return dp[i][x];
        int nottake=solve(i-1,x,num,dp);
        int take=INT_MAX;
        if(num[i]<=x)
            take=1+solve(i,x-num[i],num,dp);
        return dp[i][x]=min(nottake,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int x=0;x<=amount;x++)
            dp[0][x]=x%coins[0]==0?x/coins[0]:1e9;
        
        
        for(int i=1;i<n;i++)
        {
            for(int x=0;x<=amount;x++)
            {
                int nottake=dp[i-1][x];
                int take=INT_MAX;
                if(coins[i]<=x)
                    take=1+dp[i][x-coins[i]];
                dp[i][x]=min(nottake,take);
            }
        } 
        return dp[n-1][amount]!=1e9?dp[n-1][amount]:-1;
    }
};