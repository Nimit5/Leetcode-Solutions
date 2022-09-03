class Solution {
public:
    void dfs(int curr, int nod, int k, vector<int> &res)
    {
        if(nod==0)
            res.push_back(curr);
        else
        {
            int lastDigit=curr%10;
            if(lastDigit+k<=9)
                dfs(curr*10+lastDigit+k,nod-1,k,res);
            if(k!=0 && lastDigit>=k)
                dfs(curr*10+(lastDigit-k),nod-1,k,res);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        for(int nums=1;nums<=9;nums++)
            dfs(nums,n-1,k,res);
        return res;
    }
};