class Solution { // using recursion and backtracking
public:
    bool isValidConfig(vector<vector<int>>& grid, int r, int c, int n, int expectedVal){
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c] != expectedVal)
        return false;

        if(expectedVal == n*n - 1)
        return true;

        int ans1 = isValidConfig(grid, r-2, c+1, n, expectedVal + 1);
        int ans2 = isValidConfig(grid, r-2, c-1, n, expectedVal + 1);
        int ans3 = isValidConfig(grid, r+2, c+1, n, expectedVal + 1);
        int ans4 = isValidConfig(grid, r+2, c-1, n, expectedVal + 1);
        int ans5 = isValidConfig(grid, r-1, c+2, n, expectedVal + 1);
        int ans6 = isValidConfig(grid, r+1, c+2, n, expectedVal + 1);
        int ans7 = isValidConfig(grid, r-1, c-2, n, expectedVal + 1);
        int ans8 = isValidConfig(grid, r+1, c-2, n, expectedVal + 1);

        return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        return isValidConfig(grid, 0, 0, n, 0);
    }
};