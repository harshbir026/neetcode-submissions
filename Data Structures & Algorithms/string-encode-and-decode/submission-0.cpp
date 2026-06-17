class Solution {
   public:
    string encode(vector<string>& strs) {
        string temp = "";
        for(auto c : strs){
            temp += to_string(c.length()) + '#' + c;
        }
        return temp;
    }

    vector<string> decode(string s) {
        
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            
            int hashPos = s.find('#', i);
            
            
            int len = stoi(s.substr(i, hashPos - i));
            
            
            string word = s.substr(hashPos + 1, len);
            decoded.push_back(word);
            
           
            i = hashPos + 1 + len;
        }
        
        return decoded;
    }
};
