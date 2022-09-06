class Solution {
public:
    int find(int node, vector<int>&parent)
    {
        if(node!=parent[node]){
            parent[node]=find(parent[node],parent);
        }
        return parent[node];
    }
    bool union_edge(int u, int v, vector<int>&parent, vector<int>&rank)
    {
        int par_u=find(u,parent);
        int par_v=find(v,parent);
        if(par_u == par_v){
            return false;
        }
        
        if(rank[par_u]>rank[par_v])
        {
            parent[par_v]=par_u;
            rank[par_u]+=rank[par_v];
        }
        else{
            parent[par_u]=par_v;
            rank[par_v]+=rank[par_u];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n+1),parent(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            rank[i] = 1;
        }
        for(auto edge:edges)
        {
            if(!union_edge(edge[0],edge[1],parent,rank))
            {
                return edge;
            }
        }
        return {};
    }
};