class Solution {
public:
    // Passed string by const reference to save memory
    bool isPalindrome(int start, int end, const string& s) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void partitionHelper(vector<vector<string>>& res, vector<string>& temp, const string& s, int ind) {
        
        if (ind == s.size()) {
            res.push_back(temp);
            return;
        }
        
        
        for (int i = ind; i < s.size(); i++) {
            
            
            if (isPalindrome(ind, i, s)) {
                
                temp.push_back(s.substr(ind, i - ind + 1));
                
                
                partitionHelper(res, temp, s, i + 1);
                
                
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        partitionHelper(res, temp, s, 0);
        return res;
    }
};