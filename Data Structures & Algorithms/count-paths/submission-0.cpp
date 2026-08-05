class Solution {
public:
    int dpp(int n , int m ,vector<vector<int>>& dp,int i , int j){
        if(i<0 | j<0 || i>=n || j>=m){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right = dpp(n,m,dp,i+1,j);
        int down = dpp(n,m,dp,i,j+1);
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dpp(m,n,dp,0,0);

    }
};
