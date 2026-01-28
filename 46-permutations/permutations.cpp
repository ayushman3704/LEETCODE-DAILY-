class Solution { // backtracking (permutation)
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& curr) {

        // If current permutation is complete
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Try all unused elements
        for(int i = 0; i < nums.size(); i++) {

            if(used[i]) continue;

            // Choose
            used[i] = true;
            curr.push_back(nums[i]);

            // Explore
            backtrack(nums, used, curr);

            // Un-choose (BACKTRACK)
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> curr;

        backtrack(nums, used, curr);
        return ans;
    }
};