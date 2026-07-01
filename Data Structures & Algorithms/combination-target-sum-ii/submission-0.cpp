class Solution {
   public:
    void subsum(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int k,
                int ind, int sum) {
        if (sum == k) {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (sum + candidates[i] > k) {
                break;
            }
            temp.push_back(candidates[i]);
            subsum(res, temp, candidates, k, i + 1, sum + candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        subsum(res, temp, candidates, target, 0, 0);
        return res;
    }
};
