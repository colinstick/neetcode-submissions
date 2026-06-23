class Solution {
public:
    int n, m;
    void ff(int x, int y, vector<vector<char>>& grid) {
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        if(grid[x][y] != '1') return;
        grid[x][y] = 'v';

        ff(x+1,y,grid);
        ff(x-1,y,grid);
        ff(x,y+1,grid);
        ff(x,y-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(); m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    ff(i,j,grid);
                }
            }
        }

        return ans;
    }
};
