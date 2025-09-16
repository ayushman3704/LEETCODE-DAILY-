class Solution { // using backtracking
public:
    int res = 0;
    int m;
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(int i, int j, vector<vector<int>>& grid, int nonObstical){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == -1)
        return;

       if(grid[i][j] == 2){ // if we reached at ending square 
            if(nonObstical == 0) // check if we moved through all non obstical then increase res
            res++;

            return;
        }

        grid[i][j] = -1; // mark every visited cell as -1 so that we can't visit is again
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            solve(new_i, new_j, grid, nonObstical-1);
        }
        grid[i][j] = 0; // backtrack and mark visited cell as nonObstical cell (non visited)

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int nonObstical = 1; // initialised with 1 because starting square is also non Obstical

        int start_i;
        int start_j;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    nonObstical++;
                }
                if(grid[i][j] == 1){ // find starting square cell 
                    start_i = i;
                    start_j = j;
                }
            }
        }
        
        solve(start_i, start_j, grid, nonObstical);
        return res;
    }
};