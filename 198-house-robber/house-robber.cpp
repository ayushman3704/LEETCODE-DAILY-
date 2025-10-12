class Solution { // bottom up
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1, 0);

        dp[n] = 0;
        dp[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            int steal = nums[i] + dp[i + 2];
            int skip = dp[i+1];

            dp[i] = max(steal, skip);
        }

        return dp[0];
    }
};