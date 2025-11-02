class Solution { // using dfs
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n, int direction){
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 1 || grid[row][col] == 2){
            return;
        }

        grid[row][col] = 3; // mark visited cell

        if(direction == 1){ // up
            dfs(grid, row-1, col, m, n, direction);
        }else if(direction == 2){ // down
            dfs(grid, row+1, col, m, n, direction);
        }else if(direction == 3){ // lefr
            dfs(grid, row, col-1, m, n, direction);
        }else
        dfs(grid, row, col+1, m, n, direction); // right

    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(const auto& guard : guards){ // fill grid with guard 
            int i = guard[0];
            int j = guard[1];

            grid[i][j] = 1;
        }

        for(const auto & wall : walls){ // fill grid with wall 
            int i = wall[0];
            int j = wall[1];

            grid[i][j] = 2;
        }

        for(const auto& guard : guards){ // finally mark all guard cells 
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow-1, guardCol, m, n, 1); // up
            dfs(grid, guardRow+1, guardCol, m, n, 2); // down
            dfs(grid, guardRow, guardCol-1, m, n, 3); // left
            dfs(grid, guardRow, guardCol+1, m, n, 4); // right 
        }

        int unguaredCell = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0)
                unguaredCell++;
            }
        }

        return unguaredCell;
    }
};