class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        
        int m = matrix[0].size();
        int n = matrix.size();
        
        int bottom = n-1;
        
        while(top<=bottom){
            int row = (top+bottom)/2;
            if(target>matrix[row][m-1]){
                top = row +1;
            }else if(target<matrix[row][0]){
                bottom = row-1;
            }else{
                break;
            }
        }
        if (!(top <= bottom)) {
            return false;
        }
        int row = (top+bottom)/2;
        int l = 0;
        int r = m-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target<matrix[row][mid]){
                r = mid -1;
            }else if(target>matrix[row][mid]){
                l = mid + 1;
            }else{
                return true;
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
