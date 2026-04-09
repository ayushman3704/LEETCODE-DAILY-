class Solution { // prefix sum and suffix product
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int n = nums.size();

        vector<long long> prefix(n, 0);

        for(int i = 1; i < n; i++){

            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int ans = -1;
        long long suffix_prod = 1;

        const long long LIMIT = 1e15;

        for(int i = n-1; i >= 0; i--){

            if(prefix[i] == suffix_prod)
            ans = i;

            // Prevent overflow
            if (nums[i] != 0 && suffix_prod > LIMIT / nums[i]) {
                suffix_prod = LIMIT;
            } else {
                suffix_prod *= nums[i];
            }
        }

        return ans;
    }
};