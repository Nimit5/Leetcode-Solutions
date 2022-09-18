class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1,0);
        for(int x=0;x<=amount;x++)
            prev[x]=x%coins[0]==0?x/coins[0]:1e9;
        for(int i=1;i<coins.size();i++){
            vector<int>curr(amount+1,0);
            for(int x=0;x<=amount;x++)
                curr[x]=min(prev[x],coins[i]<=x?1+curr[x-coins[i]]:INT_MAX);
            prev=curr;
        } 
        return prev[amount]!=1e9?prev[amount]:-1;
    }
};