class Solution {
public:
    int dpp(vector<int>& nums,vector<int>& dp,int end,int start){
        if(end< start) return 0;
        if(end == start) return nums[start];
        if(dp[end]!=-1){
            return dp[end];
        }
        int rob = nums[end] + dpp(nums,dp,end-2,start);
        int notRob = dpp(nums,dp,end-1,start);
        return dp[end] = max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int>dp2(n,-1);
        int case1 = dpp(nums,dp1,n-1,1);
        int case2 = dpp(nums,dp2,n-2,0);
        return max(case1,case2);
    }
};
