class Solution {
public:
    bool isAnagram(string s, string t) {
        int mpp[26] ={0};
        for(int i = 0;i<s.length();i++){
            mpp[s[i]-'a']++;
            
        }
        for(int i = 0;i<t.length();i++){
            mpp[t[i]-'a']--;
            
        }
        for(int i = 0;i<26;i++){
            if(mpp[i]!=0){
                return false;
            }
        }
        return true;
    }
};
