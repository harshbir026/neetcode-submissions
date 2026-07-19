class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Step 1: Find the carry bits (where both a and b have a 1)
            // We use unsigned int to prevent C++ errors when left-shifting negative numbers
            unsigned int carry = (a & b);
            
            // Step 2: Add the bits together, ignoring the carry for now
            a = a ^ b;
            
            // Step 3: Shift the carry left by 1 so it gets added to the next column
            b = carry << 1;
        }
        
        // When b becomes 0, there is nothing left to carry, and 'a' holds the final sum
        return a;
    }
};