class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        int num = n;
        while(true){
            int sum = 0;
            
            while(num!=0){
                int dig = num%10;
                sum+=dig*dig;
                num/=10;
            }
            if(sum == 1){
                return true;

            }
            if(st.find(sum)!=st.end()){
                return false;
            }
            st.insert(sum);
            num = sum;
        }
    }
};
