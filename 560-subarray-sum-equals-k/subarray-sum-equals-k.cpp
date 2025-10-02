class Solution { // pattern- Prefix Sum / Running Sum
public: 
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mp;
        int accSum = 0; // store prefix sum
        mp.insert({0, 1});

        for(int i = 0; i < n; i++){
            accSum += nums[i];

            if(mp.find(accSum - k) != mp.end()){
                ans += mp[accSum - k];
            }

            mp[accSum]++;
        }

        return ans;
    }
};