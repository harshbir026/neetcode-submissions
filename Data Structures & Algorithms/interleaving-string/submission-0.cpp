class Solution {
public:
    int dpp(string&s1,string&s2,string&s3,vector<vector<int>>& dp,int i ,int j){
        if(i == s1.size() && j == s2.size()){
            return true;

        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool canForm = false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            canForm = canForm || dpp(s1,s2,s3,dp,i+1,j);
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            canForm = canForm || dpp(s1,s2,s3,dp,i,j+1);
        }
        return dp[i][j]  = canForm;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
    int m = s2.size();
    if(n+m!=s3.size()) return false;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return dpp(s1,s2,s3,dp,0,0);
    }
};
