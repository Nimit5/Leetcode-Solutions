class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            int u=it[0],v=it[1],w=it[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j)
                    dist[i][j]=0;
            
        for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if((dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX) && dist[i][j]>(dist[i][k]+dist[k][j]))
	                    dist[i][j]=dist[i][k]+dist[k][j];
	            }
	        }
	    }
        int ans=101,idx=-1;
        for(int i=0;i<n;i++)
	    {
            int count=0;
            for(int j=0;j<n;j++)
            {
                //cout<<dist[i][j]<<" ";
                if(i!=j && dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=ans)
            {
                ans=count;
                idx=i;
            }
            //cout<<"\n";
        }
        return idx;
    }
};