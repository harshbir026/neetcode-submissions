class Solution {
public:
    int f(vector<vector<int>>& dp, string& word1, string& word2, int i, int j) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = f(dp, word1, word2, i - 1, j - 1);
        } else {
            return dp[i][j] = 1 + min(f(dp, word1, word2, i, j - 1),
                                      min(f(dp, word1, word2, i - 1, j),
                                          f(dp, word1, word2, i - 1, j - 1)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(dp, word1, word2, n - 1, m - 1);
    }
};