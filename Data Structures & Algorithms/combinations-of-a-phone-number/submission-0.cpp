class Solution {
public:
    void comb(vector<string>& res,string&s,string combos[],string digits,int ind){
        if(ind == digits.size()){
            res.push_back(s);
            return;
        }
        int digit = digits[ind]-'0';
        for(int i = 0;i<combos[digit].size();i++){
            s.push_back(combos[digit][i]);

            comb( res, s,combos, digits, ind + 1);

            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        string combos[] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string s= "";
        
        comb(res,s,combos,digits,0);
        
        return res;
    }
};
