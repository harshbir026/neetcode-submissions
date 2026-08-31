class Solution {
public:
    int dpp(vector<int>& nums,vector<vector<int>>& dp,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            int coins = nums[i-1]*nums[k]*nums[j+1];
            int remainingCoins = dpp(nums,dp,i,k-1) + dpp(nums,dp,k+1,j);
            maxi = max(maxi,coins + remainingCoins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return dpp(nums,dp,1,n);
    }
};
