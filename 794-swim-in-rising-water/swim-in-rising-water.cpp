class Solution { // similar to problem path with minimum effort (1631). only change is that source cell is grid[0][0] which may have value other than 0. so we have to pass grid[0][0] instead of 0. and no need of absolute difference 
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto isSafe = [&](int x, int y){
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>> result(m, vector<int> (n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        // queue<P> pq;

        pq.push({grid[0][0], {0, 0}}); // ({distance, {row, col}}), here distance grid[0][0]
        result[0][0] = grid[0][0]; // result[0][0] me grid[0][0] means top left square (0, 0). ke value ko store krenge

        while(!pq.empty()){
            int diff = pq.top().first; // distance 
            auto coordinate = pq.top().second; // cell of binary matrix
            int x = coordinate.first; // row 
            int y = coordinate.second; // col
            pq.pop();

            if(x == m-1 && y == n-1)
            return diff;

            for(auto dir: directions){
                int x_ = x + dir[0]; // new row or nebr row 
                int y_ = y + dir[1]; // new col 

                if(isSafe(x_, y_)){
                    int maxDiff = max(diff, grid[x_][y_]); 

                    if(result[x_][y_] > maxDiff){ // dijkstra's condition
                      result[x_][y_] = maxDiff;
                      pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};