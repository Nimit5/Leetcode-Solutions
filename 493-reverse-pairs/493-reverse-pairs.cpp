class Solution {
public:
    int merge(int low, int mid, int high, vector<int>& nums)
    {
        int count=0;
        int i,j=mid+1,k=0;
        int temp[high-low+1];
        for(i=low;i<=mid;i++)
        {
            while(j<=high && (long) nums[i]> (long) 2*nums[j])
                j++;
            count+=(j-(mid+1));
        }
        int left=low,right=mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
                temp[k++]=nums[left++];
            else
                temp[k++]=nums[right++];
        }
        while(left<=mid)
            temp[k++]=nums[left++];
        
        while(right<=high)
            temp[k++]=nums[right++];
        
        for (int i = 0; i < high - low + 1; i++)
            nums[low + i] = temp[i];

        return count;
    }
    int mergesort(int low, int high, vector<int>& nums)
    {
        if(low>=high)
            return 0;
        int mid=low+(high-low)/2;
        int rev=mergesort(low,mid,nums);
        rev+=mergesort(mid+1,high,nums);
        rev+=merge(low,mid,high,nums);
        return rev;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};