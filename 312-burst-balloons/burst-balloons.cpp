class Solution { // recursion + memoization. this problem is similar to problem- 1547. Pattern- Interval DP
public:
    int t[303][303];
    int solve(vector<int>& nums, int l, int r){
        if(r - l < 2)
        return 0;

        if(t[l][r] != -1)
        return t[l][r];

        int res = INT_MIN;

        for(int k = l+1; k <= r-1; k++){
            int coins = nums[l]*nums[k]*nums[r] + solve(nums, l, k) + solve(nums, k, r);

            res = max(res, coins);
        }
        return t[l][r] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(begin(nums), 1);
        nums.push_back(1);

        memset(t, -1, sizeof(t));

        return solve(nums, 0, nums.size()-1);
    }
};