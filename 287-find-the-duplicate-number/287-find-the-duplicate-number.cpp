class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])]<0)
                break;
            nums[abs(nums[i])]*=-1;
        }
        return abs(nums[i]);
    }
};