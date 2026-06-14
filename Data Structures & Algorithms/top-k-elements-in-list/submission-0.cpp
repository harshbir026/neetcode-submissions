class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> freqList;
        for (auto it : mpp) {
            freqList.push_back({it.second, it.first});
        }
        sort(freqList.rbegin(),freqList.rend());
        vector<int> ans;
        for(int i = 0;i<k;i++){
            ans.push_back(freqList[i].second);
        }
        return ans;
    }
};
