class Solution {
   public:
    bool dpp(string& s, vector<int>& dp, unordered_set<string>& st, int start, int maxLen) {
        int n = s.size();
        if (start == n) return true;
        if (dp[start] != -1) return dp[start];
        for (int end = start; end < n; end++) {
            int currLen = end - start + 1;
            if (currLen > maxLen) {
                break;
            }
            string currWord = s.substr(start, currLen);
            if (st.find(currWord) != st.end()) {
                if (dpp(s, dp, st, end + 1, maxLen)) {
                    return dp[start] = 1;
                }
            }
        }
        return dp[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int maxLen = INT_MIN;
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }
        vector<int> dp(n, -1);
        return dpp(s, dp, st, 0, maxLen) == 1;
    }
};
