class Solution { // Using Memoization. It is similar to "Coin Change"
public:

    // int solve(int n, vector<int> &dp){

    //     if(n == 0) return 0;

    //     if(dp[n] != -1)
    //     return dp[n];

    //     int ans = 1e9;

    //     for(int i = 1; i*i <= n; i++){
    //         ans = min(ans, 1 + solve(n-i*i, dp));
    //     }

    //     return ans;
    // }

    int numSquares(int n) {
        
        vector<int> dp(n+1, 1e9);

        dp[0] = 0;


        for(int i = 1; i <= n; i++){
            for(int k = 1; k*k <= n; k++){

                if(k*k <= i){
                    dp[i] = min(dp[i], 1 + dp[i - k*k]);
                }
            }
        }

        if(dp[n] == 1e9)
        return -1;

        return dp[n];
    }
};