class Solution {
public:
    bool visited[207][207];
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        if(visited[x][y] || board[x][y] != 'O') return;
        visited[x][y] = true;
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size(); m = board[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) visited[i][j] = false;

        // "mark" all ones to NOT turn!!
        for(int i=0; i<n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int j=0; j<m; j++) {
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }

        // go thru
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
