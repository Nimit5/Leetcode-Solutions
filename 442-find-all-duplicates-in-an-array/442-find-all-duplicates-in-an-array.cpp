class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>ans;
    vector<int> findDuplicates(vector<int>& nums) {
        for(auto it:nums)
        {
            if(mp.count(it)>=1)
            {
                ans.push_back(it);
            }
            mp[it]++;
        }
        return ans;
    }
};