class Solution {
public:
    void parenthise(vector<string>& res,string& s ,int n ,int left ,int right){
        if(left==n && right==n){
            res.push_back(s);
            return;
        }
        if(left<n ){
            s.push_back('(');
            parenthise(res,s,n,left+1,right);
            s.pop_back();
        }
        if(right<n && left>right){
            s.push_back(')');
            parenthise(res,s,n,left,right+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "(";
        parenthise(res,s,n,1,0);
        return res;
    }
};
