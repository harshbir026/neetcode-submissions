class Solution {
public:
    int solve ( vector<int>& nums,vector<int>& dp,int ind){
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + solve(nums,dp,ind-2);
        int notPick = solve(nums,dp,ind-1);
        return dp[ind] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,dp,nums.size()-1);
    }
};