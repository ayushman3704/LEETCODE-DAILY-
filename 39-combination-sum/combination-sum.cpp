class Solution { // recursion and backtracking. take or not take 
public:
    set<vector<int>> st; // ensure that no duplicates combinations get stored in res
    void solve(vector<int>& candidates, int ind, vector<int> &temp, vector<vector<int>> &res, int target){
        if(ind == candidates.size() || target < 0){
            return;
        }
        if(target == 0){
            if(st.find(temp) == st.end()){
                res.push_back({temp});
                st.insert(temp);
            }
            return;
        }

        temp.push_back(candidates[ind]); // take
        solve(candidates, ind+1, temp, res, target-candidates[ind]); // take and increase index(ind)
        solve(candidates, ind, temp, res, target-candidates[ind]); // takde and don't increase index(ind). take element repeatedly
        temp.pop_back(); // not take

        solve(candidates, ind+1, temp, res, target); // explore 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int ind = 0;
        vector<int> temp = {};

        solve(candidates, ind, temp, res, target);

        return res;
    }
};