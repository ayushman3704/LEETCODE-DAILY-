class Solution { // maxPrefix and minPrefix.
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int prefix = 0;

        int maxPrefix = 0;
        int minPrefix = 0;

        for(int i = 0; i < nums.size(); i++){

            prefix += nums[i];

            maxPrefix = max(maxPrefix, prefix);

            minPrefix = min(minPrefix, prefix);
        }

        return maxPrefix - minPrefix;
    }
};