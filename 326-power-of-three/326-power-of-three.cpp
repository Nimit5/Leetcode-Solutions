class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        if(n%3==0)
            return isPowerOfThree(n/3);
        else return false;
    }
};
/*
1 - 1
3 - 11
9 - 1001
27 - 11011
81 - 1010001
*/