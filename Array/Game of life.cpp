The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead 
(represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following
four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births 
and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

solve in-place : Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update
                 some cells first and then use their updated values to update other cells


* we can use 
  -1 to represent a zero who need to transform to 1, 
  -2 to represent a one who need to transform to 0
* so when counting ones we need to count -2 s also
* in the end replace all -1 with 1 and -2 with 0


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        // -1 means 0 transformed to 1  so check for ( 0 || -1)
        // -2 means 1 transfromed to 0  so check for ( 1 || -2)
        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int oneCount = 0;
                for(int k = 0; k < 8; k++){
                    int r = i + directions[k].first;
                    int c = j + directions[k].second;
                    if((r >=0 && r < m) && (c >=0 && c < n) && (board[r][c] == 1 || board[r][c] == -2)){
                        oneCount++;
                    }
                }
                if(oneCount == 3 && board[i][j] == 0){
                    board[i][j] = -1;
                }
                if((oneCount < 2 || oneCount > 3) && board[i][j] == 1){
                    board[i][j] = -2;
                }
                //  SURPRISINGLY THIS CODE DID NOT WORK, BUT THE ABOVE ONE WORKED, DONT KNOW WHATS THE ISSUE
                // if(board[i][j] == 1){
                //     if(oneCount < 2 || oneCount > 3){
                //         board[i][j] = -2;
                //     }
                //     // otherwise cell lives, so no need to change
                // }
                // else if(board[i][j] == 0 && oneCount == 3){
                //     board[i][j] == -1;
                // }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == -1){
                    board[i][j] = 1;
                }
                else if(board[i][j] == -2){
                    board[i][j] = 0;
                }
            }
        }
    }
};