class Solution {
public:

    void dfs(int x, int y, int d, vector<vector<int>>& grid, vector<vector<int>>& dist) {
        // should even explore ts?
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == 0 || d > dist[x][y]) return;

        dist[x][y] = d;
        d++;

        dfs(x+1, y, d, grid, dist);
        dfs(x-1, y, d, grid, dist);
        dfs(x, y+1, d, grid, dist);
        dfs(x, y-1, d, grid, dist);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        const int INF = 1e7;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                dist[i][j] = INF;
                if(grid[i][j] == 2) dist[i][j]=0;
            }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) dfs(i,j,0,grid,dist);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) ans=max(ans, dist[i][j]); 
            }

        return ans==INF?-1:ans;
                
    }
};
