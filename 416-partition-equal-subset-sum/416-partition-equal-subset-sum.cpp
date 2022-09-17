class Solution {
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,0));
        for(int i=0;i<arr.size();i++)
            dp[i][0]=1;
        if(arr[0]<=sum)
            dp[0][arr[0]] = 1;
        for(int i=1;i<arr.size();i++)
        {
            for(int target= 1; target<=sum; target++)
            {
                bool notTaken = dp[i-1][target];
                bool taken = false;
                    if(arr[i]<=target)
                        taken = dp[i-1][target-arr[i]];
                dp[i][target]= notTaken||taken;
            }
        }
        return dp[arr.size()-1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum%2==1)
            return false;
        else
            return isSubsetSum(nums,sum/2);
    }
};