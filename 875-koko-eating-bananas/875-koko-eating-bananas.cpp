class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

/*
30 11 23 4 20
low=1 high=30 mid=15

low=16 high=30 mid=23
2 1 1 1 1 
low=4 high=5 mid=4

*/