class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int low_row=0,high_row=matrix.size()-1,mid_row;
        while(low_row<=high_row)
        {
            mid_row=(low_row+high_row)/2;
            if(target>=matrix[mid_row][0] && target<=matrix[mid_row][col-1])
            {
                int low=0,high=col-1,mid;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(matrix[mid_row][mid]==target)
                        return true;
                    else
                    {
                        if(matrix[mid_row][mid]>target)
                            high=mid-1;
                        else
                            low=mid+1;
                    }
                }
                return false;
            }
            else
            {
                if(target>matrix[mid_row][0])
                    low_row=mid_row+1;
                else
                    high_row=mid_row-1;
            }
            //cout<<"While running\n";
        }
        return false;
    }
};