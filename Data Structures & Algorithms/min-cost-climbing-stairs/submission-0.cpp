class Solution {
public:
    int dpp(vector<int>& dp,vector<int>& cost,int ind){
        if(ind == 0) return cost[0];
        if(ind ==1) return cost[1];
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind] + min(dpp(dp,cost,ind-1),dpp(dp,cost,ind-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(dpp(dp, cost, n-1), dpp(dp, cost, n-2));
    }
};
