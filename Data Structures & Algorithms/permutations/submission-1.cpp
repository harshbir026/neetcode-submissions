class Solution {
public:
    void perm(int ind, vector<int>& nums, vector<vector<int>>& res) {
        
        if (ind == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        
        for (int i = ind; i < nums.size(); i++) {
            
            
            swap(nums[ind], nums[i]);
            
            
            perm(ind + 1, nums, res);
            
           
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        
        perm(0, nums, res);
        
        return res;
    }
};
// class Solution {
//    public:
//     void perm(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int ind,
//               vector<bool>& arr) {
//         int n = nums.size();
//         if (temp.size() == n) {
//             res.push_back(temp);
//             return;
//         }
//         for (int i = 0; i < n; i++) {
//             if (arr[i]) {
//                 arr[i] = false;
//                 temp.push_back(nums[i]);
//                 perm(res, temp, nums, i + 1, arr);
//                 temp.pop_back();
//                 arr[i] = true;
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> temp;
//         vector<bool> arr(nums.size(), true);
//         perm(res, temp, nums, 0, arr);
//         return res;
//     }
// };
