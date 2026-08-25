class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;  
                
                char it = st.top();
                if ((c == ')' && it == '(') || (c == '}' && it == '{') ||
                    (it == '[' && c == ']')) {
                        st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
