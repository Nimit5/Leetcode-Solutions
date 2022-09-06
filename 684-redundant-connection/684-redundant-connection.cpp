class Solution {

public:

   int find(int node,vector<int>&parent){

        if(node!=parent[node]){

            parent[node] = find(parent[node],parent);

        }

       return parent[node];

    }

    bool unionNode(int first,int second,vector<int>&rank,vector<int>&parent){

        int p1 = find(first,parent);

        int p2 = find(second,parent);

        // already they are connected

        if(p1 == p2){

            return false;

        }

        // union by rank

        if(rank[p1]>rank[p2]){

            parent[p2] = p1;

            rank[p1]+=rank[p2];

        }

        else{

            parent[p1] = p2;

            rank[p2] += rank[p1];

        }

        return true;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int>parent(n+1),rank(n+1);

        for(int i=1;i<=n;i++){

            parent[i] = i;

            rank[i] = 1;

        }

        vector<int>ans;

        for(auto it:edges){

            if(!unionNode(it[0],it[1],rank,parent)){

                return {it[0],it[1]};

            }

        }

        return {};

       

    }

};