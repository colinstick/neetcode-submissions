class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int,int>> dirs(4);
        dirs[0] = {0, 1};
        dirs[1] = {1, 0};
        dirs[2] = {0, -1};
        dirs[3] = {-1, 0};

        vector<int> ans;

        int x=0; int y=0; int d=0;
        while(matrix[x][y] != -107) {
            cout << x << " " << y << endl;
            // add to answer, then set to -107
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -107;
            
            // check if direction needs changing
            int nx = x+dirs[d].first; int ny = y+dirs[d].second;
            if( nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size() ||
                matrix[nx][ny] == -107) {
                d++; d%=4;
            }

            // step forward
            x += dirs[d].first;
            y += dirs[d].second;

            // yer done
            if( x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() ||
                matrix[x][y] == -107) {
                break;
            }

        }

        return ans;
    }
};
