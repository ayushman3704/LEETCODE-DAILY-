class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        for(int i = 0; i < n; i++)  nums.push_back(nums[i]);
        for(int i = 0; i < n; i++)  nums.push_back(nums[i]);
        set<pair<int, int>> st;
        for(int i = 0; i < 3*n; i++)  st.insert({nums[i], i});
        vector<int> ans;
        for(int q : queries){
            q += n;
            auto it = st.lower_bound({nums[q], q});
            ans.push_back(min({n, q - prev(it)->second, next(it)->second - q}));
            if(ans.back() == n)  ans.back() = -1;
        }
        return ans;
    }
};