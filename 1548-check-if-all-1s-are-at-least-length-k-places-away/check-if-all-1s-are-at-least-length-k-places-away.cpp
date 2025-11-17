class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        int prevOneAt = -(k+1);
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                int diff = i - prevOneAt - 1;
                if(diff < k){
                    return false;
                }
                prevOneAt = i;
            }
        }
        return true;
    }
};