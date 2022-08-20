class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1000);
        dist[k]=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<times.size();j++)
            {
                if(dist[times[j][0]]+times[j][2]<dist[times[j][1]])
                {
                    dist[times[j][1]]=dist[times[j][0]]+times[j][2];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<dist[i]<<" ";
            ans=max(ans,dist[i]);
        }
        return ans==1000?-1:ans;
    }
};