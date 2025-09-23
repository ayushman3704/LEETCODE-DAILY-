class Solution { // using max-heap priority queue. APPROACH-2
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // it stores {nums[i], i}
        vector<int> result;

        int n = nums.size();

        for(int i = 0; i<n; i++) {
            
            //remove the max elements which are out of window size. ensure the size of window should be of k
            while(!pq.empty() && pq.top().second <= i-k)
                pq.pop();
            
            pq.push({nums[i], i}); //we will always find the max element at top

            if(i >= k-1) // if the window size is valid then push the top element(greater element) into the result
                result.push_back(pq.top().first);
        }
        return result;
    }
};