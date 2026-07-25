class Solution {
   public:
    void subsum(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int k, int ind,
                int sum) {
                    if(sum>k || ind==nums.size()){
                        return;
                    }
                    if(sum==k){
                        res.push_back(temp);
                        return;
                    }
                    
                    temp.push_back(nums[ind]);
                    subsum(res, temp, nums, k, ind, sum+nums[ind]);
                    temp.pop_back();
                    subsum(res, temp, nums, k, ind+1, sum);

                }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        subsum(res, temp, nums, target, 0, 0);
        return res;
    }
};
