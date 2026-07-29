class Solution {
public:
    int binSearch(vector<vector<int>>& matrix, int x, int l, int r, int rows) {
        if(l==r) return l-1;
        int mid = l + (r-l)/2;
        bool cond;
        if(rows==-1) cond = (x < matrix[mid][0]);
        else cond = (x < matrix[rows][mid]);
        if(cond) {
            r = mid;
        } else {
            l = mid+1;
        }
        return binSearch(matrix, x, l, r, rows);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowInd = binSearch(matrix, target, 0, matrix.size(), -1);
        if(rowInd < 0) rowInd = 0;
        int colInd = binSearch(matrix, target, 0, matrix[0].size(), rowInd);
        if(colInd < 0) colInd = 0;
        return matrix[rowInd][colInd]==target;
    }
};
