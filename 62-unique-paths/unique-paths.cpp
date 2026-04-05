class Solution { // bottum up. Pattern- "Grid / Matrix DP"
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));

        t[0][0] = 1;

        // for(int col = 1; col < n; col++){
        //     t[0][col] = 1;
        // }

        // for(int row = 1; row < m; row++){
        //     t[row][0] = 1;
        // }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0)
                continue;

                int up = (i > 0) ? t[i-1][j] : 0;
                int left = (j > 0) ? t[i][j-1] : 0;

                t[i][j] = up + left;
            }
        }
        return t[m-1][n-1];
    }
};