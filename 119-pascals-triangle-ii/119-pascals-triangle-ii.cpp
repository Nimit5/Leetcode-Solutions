class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp(1,1),curr;
        //if(rowIndex==0)return curr; 
        for(int i=1;i<=rowIndex;i++)
        {
            curr.resize(i+1);
            curr[0]=curr[i]=1;
            for(int j=1;j<i;j++)
                curr[j]=temp[j]+temp[j-1];
            temp=curr;
        }
        return temp;
    }
};