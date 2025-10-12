class Solution { // using recursion + memoization
public:
    int t[101];
    int solve(vector<int>& nums, int i){
        if(i >= nums.size())
        return 0;

        if(t[i] != -1)
        return t[i];

        int rob = nums[i] + solve(nums, i+2); // if rob then amount of money will increase so we add nums[i] and he has to skip next house so i+2.
        int not_rob = solve(nums, i+1);

        return t[i] = max(rob, not_rob);
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));

        return solve(nums, 0);
    }
};