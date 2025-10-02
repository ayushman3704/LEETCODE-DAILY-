class Solution { // Pattern- "Prefix Sum / Running Sum"
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1;
        int sufix = 1;
        int max_product = INT_MIN;

        for(int i = 0; i < n; i++){
           if(prefix == 0) 
           prefix = 1;

           if(sufix == 0)
           sufix = 1;

           prefix = prefix * nums[i];
           sufix = sufix * nums[n-i-1];

           max_product = max(max_product, max(prefix, sufix));
        }

        return max_product;
    }
};