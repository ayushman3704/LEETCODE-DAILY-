class Solution { // recursion + memoization.
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& t){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1)
        return grid[i][j];

        if(t[i][j] != -1)
        return t[i][j];

        if(i == m-1) // we can move only in right 
        return t[i][j] = grid[i][j] + solve(grid, i, j + 1, t);

        else if(j == n-1) // we can move only in down
        return t[i][j] = grid[i][j] + solve(grid, i+1, j, t);

        // we can move in both directions right and down
        return t[i][j] = grid[i][j] + min(solve(grid, i, j+1, t), solve(grid, i+1, j, t));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        return solve(grid, 0, 0, t);
    }
};