class Solution:
    def concatenatedBinary(self, n: int) -> int:
        a=""
        for i in range(1,n+1):
            a+=str(bin(i)[2:])
        return int(a,2)%1000000007;