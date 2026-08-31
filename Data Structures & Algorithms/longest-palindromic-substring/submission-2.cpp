class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int center = 0; center < s.size(); center++) {
            int len1 = expand(s, center, center);       // odd length
            int len2 = expand(s, center, center + 1);   // even length
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                start = center - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // loop exits one step too far, so actual palindrome length is:
        return right - left - 1;
    }
};