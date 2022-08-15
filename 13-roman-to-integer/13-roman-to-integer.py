class Solution:
    def romanToInt(self, s: str) -> int:
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        ans=0
        l=len(s)
        for i in range(l-1,-1,-1):
            if(i!=l-1):
                if(s[i]=='I' and s[i+1]=='V'):
                    ans-=d[s[i]]
                elif(s[i]=='I' and s[i+1]=='X'):
                    ans-=d[s[i]]
                elif(s[i]=='X' and s[i+1]=='L'):
                    ans-=d[s[i]]
                elif(s[i]=='X' and s[i+1]=='C'):
                    ans-=d[s[i]]
                elif(s[i]=='C' and s[i+1]=='D'):
                    ans-=d[s[i]]
                elif(s[i]=='C' and s[i+1]=='M'):
                    ans-=d[s[i]]
                else:
                    ans+=d[s[i]]
            else:
                ans+=d[s[i]]
        return ans