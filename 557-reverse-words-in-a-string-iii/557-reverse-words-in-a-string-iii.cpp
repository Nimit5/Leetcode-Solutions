class Solution {
public:
    string reverseWords(string s) {
        string ans="",temp;
        stringstream str(s);
        while(str>>temp)
        {
            reverse(temp.begin(),temp.end());
            ans=ans+temp+" ";
        }
        ans.pop_back();
        return ans;
    }
};