class Solution { // using BFS
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        queue<pair<pair<int, int>, int>> q;

        if(grid[0][0] == 1)
        return -1;

        q.push({{0,0}, 1});
        grid[0][0] = 1;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){

            auto front = q.front();
            q.pop();

            int x = front.first.first;
            int y = front.first.second;

            int dist = front.second;

            if(x == n-1 && y == n-1)
            return dist;

            for(int i = 0; i < 8; i++){

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0){

                    q.push({{nx, ny}, dist+1});

                    grid[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};