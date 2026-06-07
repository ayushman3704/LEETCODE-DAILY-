class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxEnding = nums[0];
        int maxSubarray = nums[0];

        int minEnding = nums[0];
        int minSubarray = nums[0];

        for(int i = 1; i < nums.size(); i++){

            maxEnding = max(nums[i], maxEnding + nums[i]);

            maxSubarray = max(maxSubarray, maxEnding);

            minEnding = min(nums[i], minEnding + nums[i]);
            minSubarray = min(minSubarray, minEnding);
        }

        return max(maxSubarray, abs(minSubarray));
    }
};