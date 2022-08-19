class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> avail,want;
        for(int i=0;i<nums.size();i++)
            avail[nums[i]]++;
        for(int i=0;i<nums.size();i++)
        {   
            if(avail[nums[i]]<=0)
                continue;
            else if(want[nums[i]]>0)
            {
                want[nums[i]]--;
                avail[nums[i]]--;
                want[nums[i]+1]++;
            }
            else if(avail[nums[i]]>0 && avail[nums[i]+1]>0 && avail[nums[i]+2]>0)
            {
                avail[nums[i]]--;
                avail[nums[i]+1]--;
                avail[nums[i]+2]--;
                want[nums[i]+3]++;
            }
            else return false;
        }
        return true;
    }
};
/*
Best Explanation -
https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/844738/Java-or-Very-easy-explanation-through-a-story-or-Time-O(n)-Space-O(n)
*/