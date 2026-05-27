class Solution { // Floyd Warshell Algorithm. 
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // Fill edges
        for(auto & e : edges){

            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }
        // Distance to itself = 0
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int bestCount = INT_MAX;

        // Count reachable cities
        for(int i = 0; i < n; i++){
            
            int count = 0;

            for(int j = 0; j < n; j++){

                if(i != j && dist[i][j] <= distanceThreshold)
                count++;
            }

            // handles tie-breaking automatically
            if(count <= bestCount){
                bestCount = count;
                ans = i;
            }
        }

        return ans;
    }
};