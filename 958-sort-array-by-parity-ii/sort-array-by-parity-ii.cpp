class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int i = 0; // pointer to even index
        int j = 1; // pointer to odd index

        while(i < n && j < n){

            while( i < n && nums[i] % 2 == 0){ // i pointer moves when nums[i] is even or at correct position
                i += 2;
            }

            while(j < n && nums[j] % 2 != 0){ // j pointer moves when nums[j] is odd or at correct position
                j += 2;
            }

            if(i < n && j < n) // incorrect position of nums[i] and nums[j] then swap them
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};