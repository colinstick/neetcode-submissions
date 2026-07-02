class Solution {
public:
    bool rowZero = false;
    bool colZero = false;
    void setULZeroes(vector<vector<int>>& matrix, int x, int y) {
        // upper left only
        if(x==0) rowZero = true;
        if(y==0) colZero = true;
        matrix[0][y] = 0;
        matrix[x][0] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        rowZero = false; colZero = false;
        // first pass: flags
        int n = matrix.size(); int m = matrix[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) setULZeroes(matrix, i, j);
            }
        }

        // second pass finish off zeros
        for(int i=1; i<n; i++) {
            if(matrix[i][0] == 0) {
                // set row to zero
                for(int j=0; j<m; j++) matrix[i][j] = 0;
            }
        }
        for(int j=1; j<m; j++) {
            if(matrix[0][j] == 0) {
                // set col to zero
                for(int i=0; i<n; i++) matrix[i][j] = 0;
            }
        }
        // corner case (LITERALLY hahahaha)
        if(colZero)
            for(int i=0; i<n; i++) matrix[i][0] = 0;
        if(rowZero)
            for(int j=0; j<m; j++) matrix[0][j] = 0;
    }
};
