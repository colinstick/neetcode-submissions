class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for(int l=0; l<n-n/2; l++) {
            // rotate rotate rotate
            for(int i=l; i<n-l; i++) {
                vector<int> temp(4);
                temp[0] = matrix[l][i];
                temp[1] = matrix[i][n-l];
                temp[2] = matrix[n-l][n-i];
                temp[3] = matrix[n-i][l];

                matrix[l][i] = temp[3];
                matrix[i][n-l] = temp[0];
                matrix[n-l][n-i] = temp[1];
                matrix[n-i][l] = temp[2];
            }

        }
    }
};
