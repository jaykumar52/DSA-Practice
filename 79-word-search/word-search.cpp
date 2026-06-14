class Solution {

    bool helper(vector<vector<char>> &board, string &word, int row, int col, int index){
        if (index==word.size()) return true;
        if (row == board.size() || col == board[0].size() || col<0 || row<0) return false;
        if (board[row][col]!=word[index]) return false;

        char c = board[row][col];
        board[row][col] = '*';
            
        bool up = helper(board, word, row - 1, col, index + 1);
        bool down = helper(board, word, row + 1, col, index + 1);
        bool left = helper(board, word, row, col - 1, index + 1);
        bool right = helper(board, word, row, col + 1, index + 1);
        board[row][col] = c;
        return up || down || right || left;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int r=0; r<board.size(); r++){
            for (int c=0; c<board[0].size(); c++){
                if (helper(board, word, r, c, 0)) return true;
            }
        }

        return false;
    }
};