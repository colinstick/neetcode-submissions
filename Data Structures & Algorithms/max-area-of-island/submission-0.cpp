class Solution {
public:
    int N, M;
    int sizeOf(int x, int y, vector<vector<int>>& grid) {
        if(x < 0 || x >= N || y < 0 || y >= M) return 0;
        if(grid[x][y] != 1) return 0;
        grid[x][y] = -1;

        return 1 + sizeOf(x+1,y,grid) +
        + sizeOf(x-1,y,grid)
        + sizeOf(x,y+1,grid)
        + sizeOf(x,y-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        N = grid.size(); M = grid[0].size();
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, sizeOf(i, j, grid));
                }
            }
        }

        return ans;
    }
};
