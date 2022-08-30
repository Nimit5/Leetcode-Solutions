class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int longest_steak=0;
        if(s.empty())
            return 0;
        for(auto it : s)
        {
            if(s.find(it-1)==s.end())
            {
                int current_num=it;
                int current_steak=1;
                
                while(s.find(current_num+1)!=s.end())
                {
                    current_num++;
                    current_steak++;
                }
                longest_steak=max(longest_steak,current_steak);
            }
        }
        return longest_steak;
    }
};
/*
0 0 1 2 3 4 5 6 7 8
*/

//2 3 5 6 6 7 8 9 