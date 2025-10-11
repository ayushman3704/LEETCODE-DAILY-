class Solution { // bottum up
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each unique power value
        unordered_map<ll, ll> mp;
        
        for (int &x : power)
            mp[x]++;

        // Step 2: \\Collect and sort unique values
        vector<ll> nums(mp.size());
        for (auto &p : mp)
            nums.push_back(p.first);

        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<ll> t(n, 0);
        //dp[i] = Maximum Total Damage if we start from index i
        
        long long result = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            //skip current value
            ll skip = (i + 1 < n) ? t[i + 1] : 0;

            //take current value
            int j   = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) - begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < n) ? t[j] : 0);

            t[i]   = max(skip, take);
            result = max(result, t[i]);
        }

        return result;
    }
};
