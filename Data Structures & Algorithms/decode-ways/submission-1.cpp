class Solution {
public:
    int dpp(string & s,vector<int>& dp,int ind){
        int n = s.size();
        if(ind == n){
            return 1;

        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int ways = dpp(s,dp,ind+1);
        if(ind + 1 <n ){
            int twoDigit = (s[ind] - '0')* 10 + (s[ind+1]-'0');
            if(twoDigit >=10 && twoDigit<=26){
                ways += dpp(s,dp,ind+2);
            }
        }
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return dpp(s,dp,0);
    }
};
