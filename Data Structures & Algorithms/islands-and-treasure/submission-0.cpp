class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            int k = q.size();
            while(k--){
                auto it = q.front();
                q.pop();
                int dist = it.first;
                int x = it.second.first;
                int y = it.second.second;

                for(int i = 0 ; i<4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 & nx<n && ny>=0 && ny<m && grid[nx][ny]==INT_MAX){
                        grid[nx][ny] = dist+1;
                        q.push({dist+1,{nx,ny}});
                    }
                }
            }
        }

    }
};
