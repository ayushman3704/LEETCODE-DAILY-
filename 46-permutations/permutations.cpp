class Solution { // backtracking. take or not take 
public:
    vector<vector<int>> res;
    int n;
    unordered_set<int> st;

    void solve(vector<int>& nums, vector<int> &temp){
        if(temp.size() == n){ // base case 
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) == st.end()){ // check if integers are not in the temp then do following
                temp.push_back(nums[i]);
                st.insert(nums[i]); // the integers which is pushed into the temp should not be pushed again into the temp

                solve(nums, temp); // every time we call recursive func for all integers of nums

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;

        solve(nums, temp);

        return res;
    }
};