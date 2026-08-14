class Solution {
public:
void subset(vector<vector<int>>& res,vector<int>& temp,int ind,vector<int> & nums){
    int n = nums.size();
    if(ind == n){
        res.push_back(temp);
        return;
    }
    subset(res,temp,ind+1,nums);
    temp.push_back(nums[ind]);
    subset(res,temp,ind+1,nums);
    temp.pop_back();
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        subset(res,temp,0,nums);
        return res;
    }
};
