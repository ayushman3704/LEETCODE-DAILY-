class Solution { // prefix sum on transformed array.  It is same as Find the longest subarray with sum = 0
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();

        for(int i = 0; i < n; i++){ // transform array. insert -1 at place 0
            nums[i] = (nums[i] == 0)? -1 : nums[i];
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        int maxlen = 0;
        int prefixsum = 0;

        for(int i = 0; i < n; i++){
            prefixsum += nums[i];

            if(mp.count(prefixsum)){
                maxlen = max(maxlen, i-mp[prefixsum]);
            }

            if(!mp.count(prefixsum))
            mp[prefixsum] = i;
        }
        return maxlen;
    }
};