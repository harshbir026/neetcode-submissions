class Solution {
public:
    int dpp(vector<int>& prices,vector<vector<int>>& dp,int ind,int buy){
        int n = prices.size();
        if(ind >= n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy==0){
            profit = max(dpp(prices,dp,ind+1,0),-prices[ind]+dpp(prices,dp,ind+1,1));
        }
        if(buy==1){
            profit = max(dpp(prices,dp,ind+1,1),prices[ind]+dpp(prices,dp,ind+2,0));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return dpp(prices,dp,0,0);
    }
};
