class Solution { // map + prefix sum + maths formula
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for (auto& [val, indices] : mp) {

            int m = indices.size();

            // prefix sum
            vector<long long> prefix(m);
            prefix[0] = indices[0];

            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }

            // Step 3: compute result
            for (int i = 0; i < m; i++) {

                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)indices[i] * i - prefix[i - 1];
                }

                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) -
                            (long long)indices[i] * (m - i - 1);
                }

                ans[indices[i]] = left + right;
            }
        }

        return ans;
    }
};