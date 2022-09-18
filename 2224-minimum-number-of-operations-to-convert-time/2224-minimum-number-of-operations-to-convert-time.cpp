class Solution {
public:
    int convertTime(string current, string correct) {
        int curr=60*stoi(current.substr(0,2))+stoi(current.substr(3,2));
        int corr=60*stoi(correct.substr(0,2))+stoi(correct.substr(3,2));
        int diff=corr-curr,ans=0,i=0;
        int arr[4]={60,15,5,1};
        while(diff!=0)
        {
            if(diff>=arr[i])
            {
                diff-=arr[i];
                ans++;
            }
            else
                i++;
        }
        return ans;
    }
};