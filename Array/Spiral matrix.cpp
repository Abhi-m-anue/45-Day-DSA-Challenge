Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100


Intuition
- My first thought on how to solve this problem is to use a boundary-based approach to traverse the matrix in a spiral order.
- I would initialize four pointers (left, right, top, and bottom) to represent the boundaries of the matrix and then move 
  these pointers inward as I traverse the matrix.

Approach
- The approach is to use a while loop to iterate through the matrix, and in each iteration, traverse the elements in the 
  following order: top row from left to right, right column from top to bottom, bottom row from right to left, and left
  column from bottom to top.
- After each traversal, move the corresponding boundary pointer inward to mark the traversed elements as visited.


NOTE:: 
* Read the code well, how/which boudaries are changed after each for loop
* the last 2 for loops needed an if statement, because since, top++ and right--  happened before them, this could have breaked
  our while loops condition.  while(left <= right && top <= bottom)
* only if still top<=bottom then we have an array to traverse from left to right {array lies in between top and bottom}
* similarly only if still left<=right we have an array to traverse from bottom to up {array lies in between left and right}


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0;
        int right = n-1;
        int bottom = m-1;
        int left = 0;
        vector<int> spiral;

        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                spiral.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            

            if(left <= right){
               for(int i = bottom; i >= top; i--){
                    spiral.push_back(matrix[i][left]);
                }
                left++; 
            }
            
        }
        return spiral;

    }
};