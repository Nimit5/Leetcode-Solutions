class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size()/2;
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        int j=0,k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                nums[i]=even[j++];
            else
                nums[i]=odd[k++];
        }
        return nums;
    }
};