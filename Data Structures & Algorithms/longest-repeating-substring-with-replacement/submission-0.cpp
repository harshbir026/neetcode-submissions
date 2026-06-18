class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;
        unordered_map<char,int>mpp;
        int maxi = 0;
        int maxF = INT_MIN;
        while(r<n){
            mpp[s[r]]++;
            maxF = max(maxF,mpp[s[r]]);
            while((r-l+1)-maxF>k){
                mpp[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
