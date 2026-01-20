class Solution { // bit manipulation
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int x = nums[i];

            if(x == 2){ // special case
                ans[i] = -1;
                continue;
            }

            // find first rightmost 0 bit
            int bit = 0;
            while(x & (1 << bit)){
                bit++;
            }

            ans[i] = x - (1 << (bit - 1));
        }
        return ans;
    }
};