class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // we can take mid any of matrix[m-1][0] or matrix[0][n-1]. here consider mid as matrix[0][n-1]
        int r = 0; 
        int c = n-1;

        while(r < m && c >= 0){
            if(target == matrix[r][c])
            return true;

            else if(target < matrix[r][c])
            c--;
            else 
            r++;
        }
        return false;
    }
};