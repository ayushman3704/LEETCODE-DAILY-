class Solution { // Patten- "Prefix Sum / Running Sum".
                // similar to leetcode- 560
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int rem = sum % k;

            if(rem < 0)
            rem += k;

            if(mp.find(rem) != mp.end()){
                res += mp[rem];
            }

            mp[rem]++;
        }

        return res;
    }
};