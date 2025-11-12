class Solution { // simple simulation
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
            count1++;
        }
        if(count1 > 0)
        return n-count1;

        int minStepTo1 = INT_MAX;

        for(int i = 0; i < n; i++){
            int GCD = nums[i];

            for(int j = i+1; j < n; j++){
                GCD = gcd(GCD, nums[j]);
                
                if(gcd(GCD, nums[j]) == 1){
                    minStepTo1 = min(minStepTo1, j-i); // ek element ko one banane me minimum kitna operation lga
                    break;
                }
                
            }
        }
        if(minStepTo1 == INT_MAX)
        return -1;

        return minStepTo1 + (n-1); // ek element ko 1 banane me jitna min operation lga + ek one minimum number of operations to make all elements of nums equal to 1.
    }
};