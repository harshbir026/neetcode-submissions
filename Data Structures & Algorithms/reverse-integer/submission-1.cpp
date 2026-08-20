#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            // Pop the last digit
            int pop = x % 10;
            x /= 10;
            
            // Anticipate positive overflow
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            
            // Anticipate negative overflow
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            // Push the digit onto the reversed number
            rev = rev * 10 + pop;
        }
        
        return rev;
    }
};