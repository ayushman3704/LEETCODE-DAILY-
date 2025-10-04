class Solution { 
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;

        // 1. find traspose of the given matrix
        for(int i = 0; i < m; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. reverse the row 
        for(int i = 0; i < m; i++){
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};