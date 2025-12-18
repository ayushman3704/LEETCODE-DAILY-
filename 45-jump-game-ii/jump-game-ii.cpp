class Solution { // Greedy Approach. 
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1)
        return 0;

        int maxReach = 0;
        int jump = 0;
        int currEnd = 0;

        for(int i = 0; i < n-1; i++){
            maxReach = max(maxReach, i + nums[i]);

            if(i == currEnd){
                jump++;
                currEnd = maxReach;
            }
        }
        if(currEnd >= n-1)
        return jump;

        return -1;
    }
};