class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int len=sizeof(arr)/sizeof(arr[0]);
    unordered_map<string,int> mp;
    for(int i=0;i<words.size();i++)
    {
        string s="";
        for(int j=0;j<words[i].size();j++)
        {
            s+=arr[char(words[i][j])-'a'];
        }
        mp[s]++;
    }
    return mp.size();
    }
};