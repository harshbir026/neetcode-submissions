class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);   
        return dfs(0, s, dict, dp);
    }

    bool dfs(int start, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if (start == s.length()) {
            return true;
        }
        if (dp[start] != -1) {
            return dp[start];   
        }

        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            if (dict.find(word) != dict.end()) {
                if (dfs(end, s, dict, dp)) {
                    return dp[start] = 1; //
                    
                }
            }
        }

        return dp[start] = 0; //
        
    }
};