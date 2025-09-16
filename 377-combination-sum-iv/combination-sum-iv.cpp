class Solution { // backtracking. take or not take. APPROACH-2 (using for loop)
                // memoized the solution
public:
    int n;
    int t[201][1001];

    int solve(int ind, vector<int>& nums, int target){
        if(ind >= n || target < 0){
            return 0;
        }
        if(target == 0)
        return 1;

        if(t[ind][target] != -1)
        return t[ind][target];

        // int take = solve(0, nums, target - nums[ind]); // when we take nums[ind] then start ind from 0(starting of the nums)
        // int not_take = solve(ind + 1, nums, target); // when we not take nums[ind] then increase ind by 1

        int result = 0;
        for(int i = ind; i<n; i++) {
            int take_i   = solve(0, nums, target-nums[i]);
            
            result += take_i;
        }

       // return t[ind][target] = take + not_take;

       return t[ind][target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(0, nums, target);
    }
};