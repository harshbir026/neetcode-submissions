class Solution {
public:
    int dpp(string& s,string& p,vector<vector<int>>& dp,int i,int j){
        int n = s.length();
        int m = p.length();
        if (j == m) return i == n;
        
        
        if (dp[i][j] != -1) return dp[i][j];
        
       
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
        
        // LOOKAHEAD: Is the NEXT character in the pattern a '*'?
        if (j + 1 < m && p[j + 1] == '*') {
            // Option 1: Match ZERO occurrences (skip the char and the '*') -> j + 2
            // Option 2: Match ONE OR MORE occurrences -> i + 1 (only if 'match' is true)
            int zeroOccurrences = dpp(s, p, dp, i, j + 2);
            int useStar = (match && dpp(s, p, dp, i + 1, j));
            
            return dp[i][j] = (zeroOccurrences || useStar);
        } 
        // Standard character match (no '*' involved)
        else if (match) {
            return dp[i][j] = dpp(s, p, dp, i + 1, j + 1);
        }
        
        // No match and no '*' to save us
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dpp(s,p,dp,0,0) == 1;
    }
};