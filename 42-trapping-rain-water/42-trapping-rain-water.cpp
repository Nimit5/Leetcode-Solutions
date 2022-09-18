class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,current=0,distance;
        stack<int>st;
        while(current<height.size())
        {
            while(!st.empty() and height[current]>height[st.top()])
            {
                int top=st.top();
                st.pop();
                
                if(st.empty())  
                    break;
                distance=current-st.top()-1;
                ans+=(min(height[current],height[st.top()])-height[top])*distance;
            }
            st.push(current++);
        }
        return ans;
    }
};