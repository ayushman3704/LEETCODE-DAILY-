class Solution { // Multi-source BFS
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;
        //directions
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // push all rotten oranges into the queue (multi-source BFS)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                fresh++;
            }
        }

        if(fresh == 0)
        return 0;

        int time = 0;

        while(!q.empty()){

            int size = q.size();

            bool rottenThisMinute = false;

            while(size--){
                
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int new_i = r + dx[i];
                    int new_j = c + dy[i];

                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1){

                        grid[new_i][new_j] = 2;

                        fresh--;

                        q.push({new_i, new_j});

                        rottenThisMinute = true;
                    }
                }
            }
            if(rottenThisMinute)
            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};