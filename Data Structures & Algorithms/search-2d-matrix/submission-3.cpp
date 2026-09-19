class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        
        int m = matrix[0].size();
        int n = matrix.size();
        
        int high = n * m -1;
        
        while( low <= high){
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col]==target){
                return true;
            }else if ( matrix[row][col] > target){
                high = mid - 1;
            }else{
               low = mid + 1;
            }
        }
        return false;
    }
};

// class Solution {
//     fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
//         val rows = matrix.size
//         val cols = matrix[0].size
//         var l = 0
//         var r = rows * cols - 1

//         while (l <= r) {
//             val m = l + (r - l) / 2
//             val row = m / cols
//             val col = m % cols
//             if (matrix[row][col] == target) {
//                 return true
//             } else if (matrix[row][col] < target) {
//                 l = m + 1
//             } else {
//                 r = m - 1
//             }
//         }
//         return false
//     }
// }
