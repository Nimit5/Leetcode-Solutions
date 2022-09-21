class Solution {
public:
    bool are_same(int c_s [],int c_p [])
    {
        for(int i=0;i<256;i++)
            if(c_s[i]!=c_p[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int c_s[256]={0};
        int c_p[256]={0};
        vector<int> ans;
        if(p.length()>s.length())
            return ans;
        for(int i=0;i<p.length();i++)
        {
            c_s[s[i]]++;
            c_p[p[i]]++;
        }
        for(int i=p.length();i<=s.length();i++)
        {
            if(are_same(c_s,c_p))
            {
                cout<<i<<"\n";
                ans.push_back(i-p.length());
            }
            c_s[s[i]]++;
            c_s[s[i-p.length()]]--;
        }
    return ans;
    }
};