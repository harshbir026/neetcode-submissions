class Solution {
   public:
    void subcnt(vector<vector<int>>& res,vector<int>& temp,vector<int>& nums,int ind){
        res.push_back(temp);
        for(int i = ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            subcnt(res,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        subcnt(res, temp, nums, 0);
        return res;
    }
};
