class Solution { // this approach: t.c O(n)  s.c O(1) (without using division operation)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // int left[n]; // left array to store product of left sides element of index i
        // int right[n]; // right array to store product of right sides elements of index i

        // left[0] = 1; 
        // right[n-1] = 1;

        vector<int> result(n);

        result[0] = 1;

        for(int i = 1; i < n; i++){ // traverse and store left product
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        int right_product = 1;
        for(int i = n-1; i >= 0; i--){
            result[i] = result[i] * right_product; // left product * right product
            right_product *= nums[i]; // update right product 
        }

        return result;
    }
};