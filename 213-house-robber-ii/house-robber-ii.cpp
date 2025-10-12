class Solution { // recusion + memoization. make this problem like "house robber I" by defining two different cases
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i >= n)
        return 0;

        if(t[i] != -1)
        return t[i];

        int rob = nums[i] + solve(nums, i+2, n); // if rob then amount of money will increase so we add nums[i] and he has to skip next house so i+2.
        int not_rob = solve(nums, i+1, n);

        return t[i] = max(rob, not_rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        // case- 1. take first house 0th and ignore n-1 house because houses are arrenged in circle
        memset(t, -1, sizeof(t));
        int take = solve(nums, 0, n-1);

        // case- 2. not take first house 0th. 
        memset(t, -1, sizeof(t));
        int not_take = solve(nums, 1, n);

        return max(take, not_take);   
    }
};