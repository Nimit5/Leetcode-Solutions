class Solution {
public:
    typedef pair<int,pair<int,int>> pop;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),cols=heights[0].size();
        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        priority_queue<pop, vector<pop>, greater<pop>> pq;
        pq.push({0,{0,0}});
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
          int effort = pq.top().first;
          int x = pq.top().second.first,y = pq.top().second.second;
          pq.pop();
          if (x == rows - 1 && y == cols - 1) 
              return effort;
          if (effort >= efforts[x][y]) 
              continue;
          efforts[x][y] = effort;
          for (int i = 0; i < 4; i++) 
          {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) 
                continue;
            int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
            pq.push({n_effort,{nx,ny}});
          }
        }
        return -1;
    }
};