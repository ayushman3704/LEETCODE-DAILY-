class Solution { // using recursion and backtracking
public:
    void solve(vector<int> &nums, vector<int> &temp, int ind, vector<vector<int>> &res ){
        if(ind >= nums.size()){ // base case
            res.push_back(temp);

            return;
        }

        temp.push_back(nums[ind]); // take
        solve(nums, temp, ind+1, res); // explore
        temp.pop_back(); // not take

        solve(nums, temp, ind+1, res); // explore
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = {};

        int ind = 0;

        solve(nums, temp, ind, res);

        return res;
    }
};