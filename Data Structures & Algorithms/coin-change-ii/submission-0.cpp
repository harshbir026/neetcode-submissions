class Solution {
public:
    int dpp(vector<int>& coins,vector<vector<int>>& dp,int ind,int amount){
        int n = coins.size();
        if(amount == 0) return 1;
        if(ind == n) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = dpp(coins,dp,ind+1,amount);
        int take = 0;
        if(coins[ind]<=amount){
            take = dpp(coins,dp,ind,amount-coins[ind]);
        }
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return dpp(coins,dp,0,amount);
    }
};
