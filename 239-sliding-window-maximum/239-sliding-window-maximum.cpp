class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++)
        {
            // removing out of window indices
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            
            // removing element that breaking decreasing order
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            // push current element to dq
            dq.push_back(i);
            
            // adding max value of window to ans 
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};