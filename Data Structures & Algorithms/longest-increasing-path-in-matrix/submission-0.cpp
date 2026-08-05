class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int r, int c){
        int n = matrix.size();
        int m = matrix[0].size();
        if(dp[r][c]!=-1) return dp[r][c];
        int maxPath = 1;
        for(int i = 0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]>matrix[r][c]){
                maxPath = max(maxPath,1 + dfs(matrix,dp,nr,nc));
            }
        }
        return dp[r][c] = maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int longestPath = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                longestPath = max(longestPath,dfs(matrix,dp,i,j));
            }
        }
        return longestPath;
    }
};
