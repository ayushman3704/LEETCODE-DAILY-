class Solution { // using sliding window
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int e = 0;
        int s = 0;
        int currsum = 0;
        int res = n+1;

        while(e<n){
            currsum += nums[e];

            while(currsum >= target && s<n){
                res = min(res, e-s+1);
                currsum -= nums[s];
                s++;
                
            } 
            e++;
        } 
       return res == n+1 ? 0 : res;
    }
};