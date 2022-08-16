class Solution:
    def firstUniqChar(self, s: str) -> int:
        d={}
        ans=-1
        for i in range(len(s)):
            try:
                d[s[i]].append(i)
            except:
                d[s[i]]=[i]
        #print(d)
        for item in d:
            if(len(d[item])==1):
                if(ans==-1):
                    ans=d[item][0]
                else:
                    ans=min(ans,d[item][0])
        return ans