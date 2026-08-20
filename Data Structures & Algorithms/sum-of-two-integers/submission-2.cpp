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

// class Solution {
// public:
//     int getSubtract(int a, int b) {
//         while (b != 0) {
//             // Step 1: Find the borrow bits
//             // We only borrow when 'a' is 0 and 'b' is 1
//             unsigned int borrow = (~a) & b;
            
//             // Step 2: Subtract the bits together, ignoring the borrow for now
//             // XOR handles subtraction without borrow perfectly
//             a = a ^ b;
            
//             // Step 3: Shift the borrow left by 1 so it gets subtracted from the next column
//             b = borrow << 1;
//         }
        
//         return a;
//     }
// };