class Solution {
public:
    bool checkValidString(string s) {
        int leftMax = 0;
        int leftMin = 0;
        for(char c : s){
            if(c=='('){
                leftMax++;
                leftMin++;
            }else if (c==')'){
                leftMax--;
                leftMin--;
            }else{
                leftMax++;
                leftMin--;
            }
            if(leftMax<0) return false;
            if(leftMin<0) leftMin = 0;
        }
        return leftMin == 0;
    }
};
