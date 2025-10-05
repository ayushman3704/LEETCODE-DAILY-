class Solution { // using multi-source BFS
public:
    vector<vector<int>> solve(vector<vector<int>>& heights, int type){
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> vis(m, vector(n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(type == 0 && (i == 0 || j == 0)){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if(type == 1 && (i == m-1 || j == n-1)){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int new_row = row + del_row[i];
                int new_col = col + del_col[i];

                if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && !vis[new_row][new_col] && heights[new_row][new_col] >= heights[row][col]){
                    q.push({new_row, new_col});
                    vis[new_row][new_col] = 1;
                }
            }
        }
        return vis;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> vis1 = solve(heights, 0); // type = 0 means pacific oceans
        vector<vector<int>> vis2 = solve(heights, 1); // type = 1 means atlantic oceans

        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis1[i][j] == 1 && vis2[i][j] == 1){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};