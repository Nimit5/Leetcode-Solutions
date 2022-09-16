class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>count;
        vector<int>ans;
        for(auto it:nums)
            for(int i=0;i<it.size();i++)
                count[it[i]]++;
        for(auto it:count)
            if(it.second==nums.size())
                ans.push_back(it.first);
        return ans;
    }
};