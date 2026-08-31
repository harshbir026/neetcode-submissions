class Solution {
public:
    int dpp(string& s,string& t,vector<vector<int>>& dp,int i , int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            int take = dpp(s,t,dp,i+1,j+1);
            int notTake = dpp(s,t,dp,i+1,j);
            return dp[i][j] = take + notTake;
        }else{
            return dp[i][j] = dpp(s,t,dp,i+1,j);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dpp(s,t,dp,0,0);
    }
};
