class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        int right = 0;
        for(int i = 0; i < n; i++){
            if(right == sum - right - nums[i])
            return i;

            right += nums[i];
        }
        return -1;
    }
};