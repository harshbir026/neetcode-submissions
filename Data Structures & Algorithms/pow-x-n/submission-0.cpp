class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n;
        if(pow < 0){
            pow = -pow;
            x = 1.0/x;

        }
        double res = 1.0;

        while( pow > 0){
            if(pow % 2 == 1){
                res *= x;
            }
            x *= x ;
            pow /= 2;
        }
        return res;
    }
};
