class Solution {
public:
    int visited[5][5];
    int n, m;
    bool foundWord(vector<vector<char>>& board, string word, int i, int x, int y) {
        if(i >= word.length()) return true;
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(board[x][y] != word[i] || visited[x][y]) return false;

        visited[x][y] = true;

        bool ret = foundWord(board, word, i+1, x+1, y) ||
               foundWord(board, word, i+1, x-1, y) ||
               foundWord(board, word, i+1, x, y+1) ||
               foundWord(board, word, i+1, x, y-1); 
        
        if(!ret) visited[x][y] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size();
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) visited[i][j] = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(foundWord(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
