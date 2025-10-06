class Solution { // using two pointer.
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = 1e5;

        sort(begin(nums), end(nums));

        for(int k = 0; k <= n-3; k++){
            int i = k + 1;
            int j = n - 1;

            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];

                if(abs(sum - target) < abs(closestSum - target))
                closestSum = sum;

                if(sum < target)
                i++;
                else
                j--;
            }
        }
        return closestSum;
    }
};

// we not need to return index in response, so 
// we can sort the given array and
// can apply two pointer approach