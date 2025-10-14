class Solution { // memoization using map. 
                 // we have two options at every index- plus or minus like take or not take.
public:
    int solve(vector<int>& nums, int i, int target, int currSum, unordered_map<string, int>& mp){
        if(i == nums.size()){
            if(currSum == target)
            return 1;
            else
            return 0;
        }
        string key = to_string(i) + "_" + to_string(currSum);
        if(mp.count(key)){
            return mp[key];
        }

        int plus = solve(nums, i+1, target, currSum+nums[i], mp);
        int mins = solve(nums, i+1, target, currSum-nums[i], mp);

        return mp[key] = plus+mins;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;

        return solve(nums, 0, target, 0, mp);
    }
};