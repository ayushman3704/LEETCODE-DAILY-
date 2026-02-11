class Solution { // using prefix sum. Same invariant as leetcode 560
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int oddCount = 0;
        int ans = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i]%2 == 1) oddCount++;

            if(mp.find(oddCount - k) != mp.end())
            ans += mp[oddCount - k];

            mp[oddCount]++;
        }

        return ans;
    }
};