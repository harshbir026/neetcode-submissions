class Solution {
public:
    int dpp(vector<int>& coins, vector<vector<int>>& dp, int amount, int ind) {
        int n = coins.size();
        
        
        if (amount == 0) return 0; 
        if (ind == n) return 1e9; 
        if (dp[ind][amount] != -1) return dp[ind][amount];
        
        
        int notTake = 0 + dpp(coins, dp, amount, ind + 1);
        
        
        int take = 1e9;
        if (amount >= coins[ind]) {
            
            take = 1 + dpp(coins, dp, amount - coins[ind], ind);
        }
        
        
        return dp[ind][amount] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = dpp(coins, dp, amount, 0);
        
        
        return ans >= 1e9 ? -1 : ans;
    }
};