class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        set<int>odd,even;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])%2==1)
            {
                odd.insert(i);
            }
            else
            {
                ans+=nums[i];
                even.insert(i);
            }
        }
        cout<<ans<<"\n";
        cout<<odd.size()<<"\n";
        cout<<even.size()<<"\n";
        for(auto q:queries)
        {
            if(even.find(q[1])!=even.end())
            {
                cout<<"Even for "<<q[0]<<","<<q[1]<<"->";
                if((q[0])%2==0)
                {
                    ans+=q[0];
                    nums[q[1]]+=q[0];
                    cout<<"even & ans="<<ans<<"\n";
                }    
                else
                {
                    ans-=nums[q[1]];
                    nums[q[1]]+=q[0];
                    even.erase(q[1]);
                    odd.insert(q[1]);
                    cout<<"odd & ans="<<ans<<"\n";
                }
            }
            else
            {
                cout<<"Odd for "<<q[0]<<","<<q[1]<<"->";
                if((q[0])%2==0)
                {
                    nums[q[1]]+=q[0];
                    cout<<"even & ans="<<ans<<"\n";
                }    
                else
                {
                    nums[q[1]]+=q[0];
                    ans+=nums[q[1]];
                    odd.erase(q[1]);
                    even.insert(q[1]);
                    cout<<"odd & ans="<<ans<<"\n";
                }
            }
            cout<<ans<<"\n";
            res.push_back(ans);
        }
        return res;   
    }
};
/*
8 -10 10 -7 4 -2
0  1  2   3 4  5

odd -3,5
even - 0,1,2,4
ans=10

*/