class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int elevation = it[0];
            int x = it[1];
            int y = it[2];
            if(x == n-1 && y == n-1) return elevation;
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    pq.push({max(elevation,grid[nx][ny]),nx,ny});
                }
            }
        }
        return -1;
    }
};
