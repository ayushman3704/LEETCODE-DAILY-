class Solution { // sliding window. Monotonic increasing/decreasing pattern.
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;

        int i = 0;
        vector<int> res;

        while(i < n){
            // step- 1. window size not be greater than k
            while(!deq.empty() && deq.front() <= i - k){
                deq.pop_front();
            }
            // step- 2. greater element should be at the front
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            // step- 3. if step- 1 and 2 satisfy then push element into the deque
            deq.push_back(i);
            // step- 4. if window size is valid then push front element of the deque into res
            if(i >= k - 1){
                res.push_back(nums[deq.front()]);
            }
            i++;
        }
        return res;
    }
};