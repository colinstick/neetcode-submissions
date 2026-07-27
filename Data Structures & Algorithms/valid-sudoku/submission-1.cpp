class Solution {
public:
    map<char, int> visited;
    bool checkRowCol(vector<vector<char>> &board, int x, bool row) {
        for(char i='1'; i<='9'; i++) visited[i] = 0;
        for(int i=0; i<9; i++) {
            if(row)
                visited[board[x][i]]++;
            else
                visited[board[i][x]]++;
        }
        for(char i='1'; i<='9'; i++) if(visited[i] > 1) return false;
        return true;
    }
    bool checkSquare(vector<vector<char>> &board, int x, int y) {
        for(char i='1'; i<='9'; i++) visited[i] = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                visited[board[x+i][y+j]]++;
            }
        }
        for(char i='1'; i<='9'; i++) if(visited[i] > 1) return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows/cols
        for(int i=0; i<9; i++) {
            if(!checkRowCol(board, i, true)) return false;
            if(!checkRowCol(board, i, false)) return false;
        }
        // check squares
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                if(!checkSquare(board, i, j)) return false;
            }
        }
        return true;
    }
};
