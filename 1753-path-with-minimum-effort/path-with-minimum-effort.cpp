class Solution { // Dijkastra's Algorithm.
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // dist matrix will store the "minimum max-effort" to reach cell (i, j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Min-Heap: {current_max_effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Start from top-left. Effort to be at the start is 0.
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int current_effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            // Optimization: Since it's Dijkstra, the first time we pop the destination, 
            // it is guaranteed to be the absolute minimum effort path.
            if(r == n - 1 && c == m - 1) {
                return current_effort;
            }
            
            // Check all 4 neighbors
            for(int i = 0; i < 4; i++) {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                
                // Boundary check
                if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
                    
                    // 1. Calculate the weight of this step (height difference)
                    int jump_weight = abs(heights[r][c] - heights[new_r][new_c]);
                    
                    // 2. The magic Bottleneck Logic derived above
                    int new_path_effort = max(current_effort, jump_weight);
                    
                    // 3. Relaxation Step: Do we strictly improve the effort to reach neighbor?
                    if(new_path_effort < dist[new_r][new_c]) {
                        dist[new_r][new_c] = new_path_effort;
                        pq.push({new_path_effort, {new_r, new_c}});
                    }
                }
            }
        }
        
        return 0; // Fallback
    }
};