class Solution { // using min-heap
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(); // size of row 
        int n = heightMap[0].size(); // size of col

        int water = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false)); // to mark visited cell or building
        priority_queue<pp, vector<pp>, greater<>> pq; // to store height and coordinate of each cell {height, {i, j}}

        // left most col and right most col i.e., {0, n-1}
        for(int row = 0; row < m; row++){
            for(int col : {0, n-1}){
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }   

        // top most row and bottum most row i.e., {o, m-1}
        for(int col = 0; col < n; col++){
            for(int row : {0, m - 1}){
                pq.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for(auto dir : directions){ // visiting nebr
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]){
                    water += max((height - heightMap[i_][j_]), 0);

                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};

// 1. push boundary cell into the pq 
// 2. from boundary cell traverse the nebr 