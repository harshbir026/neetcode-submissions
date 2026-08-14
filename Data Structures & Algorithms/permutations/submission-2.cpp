class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& res,vector<bool>& visited,vector<int>& temp){
        int n = nums.size();
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++){
            if(visited[i]){
                continue;
            }
            temp.push_back(nums[i]);
            visited[i] = true;
            helper(nums,res,visited,temp);
            visited[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool>visited(n,false);
        helper(nums,res,visited,temp);
        return res;
    }
};