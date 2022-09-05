typedef pair<long, long> pll;
#define ll long long

class Solution {
public:    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll>>adj[n];
        int mod=1e9+7;
        for(auto road : roads)
        {
            int u=road[0],v=road[1],cost=road[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        vector<ll> dist(n,LONG_MAX);
        vector<ll> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push(make_pair(0,0));
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>dist[node])
                continue;
            for(auto it:adj[node])
            {
                //it[1]->edge_weight 
                if(it[1]+dist[node]<dist[it[0]])
                {
                    dist[it[0]]=it[1]+dist[node];
                    ways[it[0]]=ways[node];
                    pq.push(make_pair(dist[it[0]],it[0]));
                }
                else if(it[1]+dist[node]==dist[it[0]])
                {
                    ways[it[0]]=(ways[it[0]]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};