//https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/1267000/C%2B%2B-3-approaches-FULL-STORY-LIKE-Explanation-(-O(n2)-Dp-greater-O(n)-dp-greater-O(nlogn)-using-max-heap-)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int curr=startFuel,count=0,i=0;
        while(curr<target)
        {
            while(i<stations.size() && curr>=stations[i][0])
            {
                pq.push(stations[i++][1]);
            }
            if(pq.empty())
                return -1;
            int dist=pq.top();
            pq.pop();
            curr+=dist;
            count++;
        }
        return count;
    }
};