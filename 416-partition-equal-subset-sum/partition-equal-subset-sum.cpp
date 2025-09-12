class Solution { // memoized approach 
public:
    // void solve(vector<int>& candidates, int ind, vector<int> &temp, vector<vector<int>> &res, int target){
    //     if(ind == candidates.size() || target < 0){
    //         return;
    //     }
    //     if(target == 0){
    //         // if(st.find(temp) == st.end()){
    //             res.push_back({temp});
    //             // st.insert(temp);
    //         // }
    //         return;
    //     }

    //     temp.push_back(candidates[ind]); // take
    //     solve(candidates, ind+1, temp, res, target-candidates[ind]); // take and increase index(ind)
    //     //solve(candidates, ind, temp, res, target-candidates[ind]); // takde and don't increase index(ind). take element repeatedly
    //     temp.pop_back(); // not take

    //     solve(candidates, ind+1, temp, res, target); // explore 
    // }

    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x) {
        if(x == 0) {
            return true;
        }

        if(i >= nums.size()) {
            return false;
        }

        if(t[i][x] != -1) {
            return t[i][x];
        }

        bool take = false;
        if(nums[i] <= x) {
            take = solve(nums, i+1, x - nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int S = accumulate(begin(nums), end(nums), 0);

        if(S%2 != 0) {
            return false;
        }  
        memset(t, -1, sizeof(t));
        //vector<vecyot<int>> t(n+1, vector<int>(x+1, -1))
        int x = S/2;

        return solve(nums, 0, x);
    }
};