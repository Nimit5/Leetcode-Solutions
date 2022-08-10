class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row>0 && image[row-1][col]==initial && image[row-1][col]!=color)
            {
                image[row-1][col]=color;
                q.push({row-1,col});
            }
            if(row<m-1 && image[row+1][col]==initial && image[row+1][col]!=color)
            {
                image[row+1][col]=color;
                q.push({row+1,col});
            }
            if(col>0 && image[row][col-1]==initial && image[row][col-1]!=color)
            {
                image[row][col-1]=color;
                q.push({row,col-1});
            }
            if(col<n-1 && image[row][col+1]==initial && image[row][col+1]!=color)
            {
                image[row][col+1]=color;
                q.push({row,col+1});
            }
        }
        return image;
    }
};