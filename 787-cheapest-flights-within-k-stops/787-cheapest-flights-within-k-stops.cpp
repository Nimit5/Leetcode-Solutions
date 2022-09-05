class Solution {
public:
    typedef pair<int,int> p;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> dist(n,1e6);
        dist[src]=0;
        for(int z=0; z<=k; z++){
            vector<int> C(dist);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], dist[e[0]] + e[2]);
            dist = C;
        }
        return dist[dst] == 1e6 ? -1 : dist[dst];
    }
};