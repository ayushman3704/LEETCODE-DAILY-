class Solution { // using recursion. we have two options at every index- plus or minus like take or not take.
public:
    int solve(vector<int>& nums, int i, int target, int currSum){
        if(i == nums.size()){
            if(currSum == target)
            return 1;
            else
            return 0;
        }

        int plus = solve(nums, i+1, target, currSum+nums[i]);
        int mins = solve(nums, i+1, target, currSum-nums[i]);

        return plus+mins;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums, 0, target, 0);
    }
};