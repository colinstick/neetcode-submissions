class Solution {
public:
    void dfs(int x, int y, int d, vector<vector<int>>& grid) {
        // should even explore ts?
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(d > grid[x][y]) return;

        grid[x][y] = d;
        d++;

        dfs(x+1, y, d, grid);
        dfs(x-1, y, d, grid);
        dfs(x, y+1, d, grid);
        dfs(x, y-1, d, grid);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0 ;j<m; j++) {
                if(grid[i][j] == 0) {
                    dfs(i, j, 0, grid);
                }
            }
        }
    }
};
