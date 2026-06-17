class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for(auto s : strs){
            vector<int> mpp(26,0);
            for(auto c : s){
                mpp[c-'a']++;
            }
            string key = to_string(mpp[0]);
            for(int i = 1;i<26;i++){
                key += ',' + to_string(mpp[i]) ;
            }
            ans[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto s : ans ){
            res.push_back(s.second);
        }
        return res;
    }
};
