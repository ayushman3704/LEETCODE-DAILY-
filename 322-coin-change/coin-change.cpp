class Solution { // using Tabulation. "UNBOUNDED KNAPSACK PROBLEM"
public:

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, 1e9);

        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){

            for(int c : coins){

                if(i - c >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        if(dp[amount] >= 1e9)
        return -1;

        return dp[amount];
    }
};