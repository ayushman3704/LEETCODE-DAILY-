class Solution { // recursion + memoization
public:
    int t[201][201];
    int solve(vector<vector<int>>& dungeon, int i, int j){
        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i == m || j == n)
        return 1e9;

        if(t[i][j] != -1)
        return t[i][j];

        if(i == m-1 && j == n-1){
            if(dungeon[i][j] > 0)
            return 1;

            return abs(dungeon[i][j]) + 1;
        }

        int right = solve(dungeon, i, j+1);
        int down = solve(dungeon, i+1, j);

        int result = min(right, down) - dungeon[i][j];

        return t[i][j] = result > 0 ? result : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(t, -1, sizeof(t));

        return solve(dungeon, 0, 0);
    }
};