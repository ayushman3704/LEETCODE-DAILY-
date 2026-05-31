class Solution { // Using Sliding Window Approach.   O(N)
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();

        int i = 0; 
        int j = 0;

        int ans = 0;

        int prod = 1;

        if(k <= 1)
        return 0;


        while(j < n){

            prod *= nums[j];

            while(prod >= k){ // shrink when window become invalid

                prod /= nums[i];
                i++;
            }

            ans += (j - i + 1); // count all subarray ending at j

            j++;
        }

        return ans;
    }
};