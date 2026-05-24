class Solution { // Graph + DP. 
public:

    vector<int> dp;
    
    int dfs(int i, vector<int>& arr, int d){

        if(dp[i] != -1){
            return dp[i];
        }

        int n = arr.size();

        int ans = 1;

        // LEFT
        for(int step = 1; step <= d; step++){

            int new_i = i - step;

            if(new_i < 0)
            break;

            // BLOCKER
            if(arr[new_i] >= arr[i])
            break;

            ans = max(ans, 1 + dfs(new_i, arr, d));
        }

        // RIGHT
        for(int step = 1; step <= d; step++){

            int new_i = i + step;

            if(new_i >= n)
            break;

            // BLOCKED
            if(arr[new_i] >= arr[i])
            break;

            ans = max(ans, 1 + dfs(new_i, arr, d));
        }

        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();

        dp.resize(n, -1);

        int ans = 1;

        for(int i = 0; i < n; i++){

            ans = max(ans, dfs(i, arr, d));
        }

        return ans;
    }
};