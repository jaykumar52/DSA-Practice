class Solution {

    bool isSafe(vector<vector<char>> &board, int row, int col, char dig){
        for (int i=0; i<9; i++){
            if (board[i][col]==dig)
            return false;
        }
        for (int j=0; j<9; j++){
            if (board[row][j]==dig)
            return false;
        }

        int sCol=(col/3)*3;
        int sRow=(row/3)*3;

        for (int r=sRow; r<=sRow+2; r++){
            for (int c=sCol; c<=sCol+2; c++){
                if (board[r][c]==dig) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col){
        if (row==9) return true;

        int nextRow=row;
        int nextCol=col+1;
        if (nextCol==9){
            nextRow++;
            nextCol=0;
        }

        if (board[row][col]!='.'){
            return helper(board, nextRow, nextCol);
        }

        for (char i='1'; i<='9'; i++){
            if (isSafe(board, row, col, i)){
                board[row][col]=i;
                if (helper(board, nextRow, nextCol)){
                    return true;    
                }
                board[row][col]='.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};