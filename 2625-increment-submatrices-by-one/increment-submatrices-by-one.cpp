class Solution { // Apply 1D Difference Array Technique (DAT) for 2D array (matrix).
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> diff(n, vector<int>(n, 0)); // declare diff matrix as 1D DAT

        for(auto query:queries){ // step-1 make diff matrix
            int r1 = query[0]; 
            int c1 = query[1];

            int r2 = query[2];
            int c2 = query[3];

            for(int i = r1; i <= r2; i++){
                diff[i][c1] += 1;

                if(c2 + 1 < n)
                diff[i][c2 + 1] -= 1;
            }
        }

        for(int i = 0; i < n; i++){ // step-2 take cummalative sum
            for(int j = 1; j < n; j++){
                diff[i][j] += diff[i][j-1];
            }
        }
        return diff;
    }
};