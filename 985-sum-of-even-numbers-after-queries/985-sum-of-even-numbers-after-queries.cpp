class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2==0)
                sum+=nums[i];
        vector<int>res;
        for(auto q:queries)
        {
            if (nums[q[1]] % 2 == 0) 
                sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if (nums[q[1]] % 2 == 0) 
                sum += nums[q[1]];
            res.push_back(sum);
        }
        return res;   
    }
};
/*
8 -10 10 -7 4 -2
0  1  2   3 4  5

odd -3,5
even - 0,1,2,4
ans=10

*/