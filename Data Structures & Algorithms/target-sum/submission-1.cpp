class Solution {
   public:
    int dpp(vector<int>& nums, vector<vector<int>>& dp, int ind, int current_sum, int target,
            int total_sum) {
        int n = nums.size();

        if (ind == n) {
            return current_sum == target ? 1 : 0;
        }

        int dp_index = current_sum + total_sum;

        if (dp[ind][dp_index] != -1) {
            return dp[ind][dp_index];
        }

        int add = dpp(nums, dp, ind + 1, current_sum + nums[ind], target, total_sum);
        int sub = dpp(nums, dp, ind + 1, current_sum - nums[ind], target, total_sum);

        return dp[ind][dp_index] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total_sum) {
            return 0;
        }

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2 * total_sum + 1, -1));

        return dpp(nums, dp, 0, 0, target, total_sum);
    }
};