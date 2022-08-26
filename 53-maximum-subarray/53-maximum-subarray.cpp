class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long int curr=0,ans=-1e8;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        return ans;
    }
};