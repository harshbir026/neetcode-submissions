class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
       
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;
        
        // Base Case 1: All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Base Case 2: Check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // General Case: Check for lengths 3 and greater
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                
                // It's a palindrome if the outer characters match 
                // AND the inner substring is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    if (length > maxLen) {
                        start = i;
                        maxLen = length;
                    }
                }
            }
        }
        
        // Extract and return the longest palindrome found
        return s.substr(start, maxLen);
    }
};