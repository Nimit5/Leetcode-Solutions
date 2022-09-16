class Solution {
public:
    int m, n;
    int dp[1000][1000];
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        n = nums.size();
        m = muls.size();
        memset(dp, INT_MIN, sizeof(dp));
        for(int i=m-1;i>=0;i--)
        {
            int len = n-i;
            for(int l = 0; l <= n-len; l++)
            {
                int end = l+len-1;   // l+n-i-1
                if(i == m-1)
                    dp[l][i] = max(nums[l]*muls[i], nums[end]*muls[i]);
                else
                    dp[l][i] = max(dp[l+1][i+1]+nums[l]*muls[i],dp[l][i+1]+nums[end]*muls[i]);
            }
        }
        return dp[0][0];
    }
};