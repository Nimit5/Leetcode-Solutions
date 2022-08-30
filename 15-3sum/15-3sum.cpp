class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),target=0;
        vector<vector<int>> total;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]>target)
                break;
            if(nums[i]+nums[n-2]+nums[n-1]<target)
                continue;
            int left=i+1,right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    total.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    do{left++;}while(nums[left]==nums[left-1]&&left<right);
                    do{right--;}while(nums[right]==nums[right+1]&&left<right);
                }
            }
        }
        return total;
    }
};