class Solution { // memoization 2D vector. 
                 // we have two options at every index- plus or minus like take or not take.
public:
    int S;
    int n;
    int solve(vector<int>& nums, int i, int target, int currSum, vector<vector<int>>& t){
        if(i == n){
            if(currSum == target)
            return 1;
            else
            return 0;
        }
        if(t[i][currSum+S] != -1){
            return t[i][currSum+S];
        }

        int plus = solve(nums, i+1, target, currSum+nums[i], t);
        int mins = solve(nums, i+1, target, currSum-nums[i], t);

        return t[i][currSum+S] = plus+mins;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        S = accumulate(begin(nums), end(nums), 0); // calculate sum and store in S

        n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(2*S+1, -1));

        return solve(nums, 0, target, 0, t);
    }
};