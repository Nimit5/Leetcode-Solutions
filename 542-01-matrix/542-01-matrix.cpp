class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dirs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty())
        {   
            pair<int,int>curr=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_row=curr.first+dirs[i][0],new_col=curr.second+dirs[i][1];
                if(new_row>=0 && new_row<row && new_col>=0 && new_col<col)
                {
                    if (dist[new_row][new_col] > dist[curr.first][curr.second] + 1)
                    {
                        dist[new_row][new_col] = dist[curr.first][curr.second] + 1;
                        q.push({ new_row, new_col });
                    }
                }
            }
        }
        return dist;
    }
};