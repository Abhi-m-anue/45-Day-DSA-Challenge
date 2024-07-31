Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


'O(m+n) soln' 

* use two arrays to store the columns and rows who has zero in them
* and in the next iteration we can use these arrays to modify the matrix

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m,false);
        vector<bool> cols(n,false);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rows[i] == true || cols[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


'Optimal' (There is a still optimised version in strivers video,where no. of loops are less)

* instead of using separate arrays we use the matrix's' first row and first column to indicate presence of zeros
* since we are over-writing first column/row we need to check whether they contain any zero, in that case we have to make 
  them entirely zero(we do this at last)




class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        bool fcol = false;
        bool frow = false;

        // Check if there is a zero in the first column, set fcol to true.
        for (int i = 0; i < rows; i++) {
            if (mat[i][0] == 0) {
                fcol = true;
                break;
            }
        }

        // Check if there is a zero in the first row, set frow to true.
        for (int i = 0; i < cols; i++) {
            if (mat[0][i] == 0) {
                frow = true;
                break;
            }
        }

        // Check row elements (by ignoring the first row and first column). If
        // zero is found, set the corresponding row's and column's first element
        // to zero.
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }

        // Check every row's first element starting from the second row.
        // Set the complete row to zero if zero is found.
        for (int i = 1; i < rows; i++) {
            if (mat[i][0] == 0) {
                for (int j = 1; j < cols; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        // Check every column's first element starting from the second column.
        // Set the complete column to zero if zero is found.
        for (int j = 1; j < cols; j++) {
            if (mat[0][j] == 0) {
                for (int i = 1; i < rows; i++) {
                    mat[i][j] = 0;
                }
            }
        }

        // If fcol is true, set the first column to zero.
        if (fcol) {
            for (int i = 0; i < rows; i++) {
                mat[i][0] = 0;
            }
        }

        // If frow is true, set the first row to zero.
        if (frow) {
            for (int j = 0; j < cols; j++) {
                mat[0][j] = 0;
            }
        }
    }
};