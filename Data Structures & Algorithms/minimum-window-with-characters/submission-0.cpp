class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (m > n) return "";
        unordered_map<char, int> mpp;
        for (auto c : t) {
            mpp[c]++;
        }
        int lim = t.length();
        int start = 0;
        int end = INT_MAX;
        int l = 0;
        int r = 0;
        while (r < n) {
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] > 0) {
                lim--;
            }
            mpp[s[r]]--;
            if (lim == 0) {
                while(true){
                    if(mpp.find(s[l])!=mpp.end() && mpp[s[l]] == 0){
                        break;
                    }
                    mpp[s[l]]++;
                    l++;
                }
                if(r - l < end - start){
                    end = r;
                    start = l;
                }
                mpp[s[l]]++;
                l++;
                lim++;
            }
            r++;
        }
        return end >= s.length() ? "" : s.substr(start,end-start+1);
    }
};
