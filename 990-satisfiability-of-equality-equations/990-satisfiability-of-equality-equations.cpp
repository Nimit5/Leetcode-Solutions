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
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> rank(26),parent(26),vis(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i] = 1;
        }
        for(auto e:equations)
        {
            int u=e[0]-'a';
            int v=e[3]-'a';
            bool op=e[1]=='='?true:false;
            if(op)
            {
                cout<<op<<" \n";
                bool t=union_edge(u,v,parent,rank);
            }    
                   
        }
        for(auto e:equations)
        {
            int u=e[0]-'a';
            int v=e[3]-'a';
            bool op=(char)e[1]=='='?true:false;
            if(!op)
            {
                 cout<<op<<" unequal\n";
                 if(find(u,parent)==find(v,parent)) 
                    return false;  
            }       
        }
        return true;
    }
};