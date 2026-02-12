class Solution { // prefix sum + hashmap. 
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();

        long long totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }

        int need = totalSum % p;

        if(need == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int minlen = n;
        int prefix = 0;

        for(int i = 0; i < n; i++){

            prefix = (prefix + nums[i])%p;

            int target = (prefix-need+p)%p;

            if(mp.count(target)){
                minlen = min(minlen, i-mp[target]);
            }

            if(!mp.empty())
            mp[prefix] = i;
        }
        return minlen == n ? -1 : minlen;
    }
};