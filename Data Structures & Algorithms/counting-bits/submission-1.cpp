class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // A number's set bits = (set bits of number / 2) + (1 if number is odd)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};