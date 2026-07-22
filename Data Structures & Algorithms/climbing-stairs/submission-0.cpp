class Solution {
public :
    int dpp(vector<int> & dp,int ind){
        if(ind == 1) return 1;
        if(ind == 2) return 2;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = dpp(dp,ind-1) + dpp(dp,ind-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dpp(dp,n);
    }
};
