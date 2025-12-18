class Solution { // bottom-up (using dp approach)
public:
    // bool solve(vector<int> &nums, int n, int ind, vector<int> &dp){
    //     if(ind == n-1)
    //     return true;

    //     // if(ind >= n)
    //     // return true;

    //     if(dp[ind] != -1)
    //     return dp[ind];

    //     for(int i = 1; i <= nums[ind]; i++){
    //         if(solve(nums, n, ind + i, dp) == true)
    //         return dp[ind] = true;
    //     }
    //     return dp[ind] = false;
    // }
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);

        dp[0] = true;
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[i] == true)
                break;
                if(dp[j] == true && j + nums[j] >= i){
                    dp[i] = true;
                }
            }
        }
        return dp[n-1];
    }
};