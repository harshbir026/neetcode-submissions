class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(char c : s){
            if(isalnum(c)){
                t+=tolower(c);
            }
        }
        string r = t;
        reverse(t.begin(),t.end());
        for(int i = 0;i<r.length();i++){
            if(r[i]!=t[i]) return false;
        }
        return true;
    }
};
