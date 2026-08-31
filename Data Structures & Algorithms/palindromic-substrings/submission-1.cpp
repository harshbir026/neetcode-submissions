class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int center = 0; center < n; center++) {
            cnt += expand(s, center, center);       // odd length
            cnt += expand(s, center, center + 1);   // even length
        }
        return cnt;
    }
    
private:
    int expand(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};