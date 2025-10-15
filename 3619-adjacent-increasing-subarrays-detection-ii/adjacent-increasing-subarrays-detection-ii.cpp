class Solution { // Using same concept as problem- "Adjacent Increasing Subarrays Detection I"
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1; // store the length of current strictly increasing subarray
        int prevRun = 0; // store the length of strictly increasing subarray

        int maxResult = 0; // store the maximum possible value of k.

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                currRun++;
            }else{
                prevRun = currRun;
                currRun = 1;
            }

            maxResult = max(maxResult, currRun/2);
            maxResult = max(maxResult, min(prevRun, currRun));
        }
        return maxResult;
    }
};