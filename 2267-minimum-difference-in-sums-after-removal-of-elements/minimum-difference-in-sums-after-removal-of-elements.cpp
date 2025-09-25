class Solution { // using heap
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(); //3*n
        int n = N/3;

        vector<long long> leftMinSum(N, 0); // store the left sum till this index
        vector<long long> rightMaxSum(N, 0); // store the right sum till this index

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for(int i = 0; i < 2*n; i++) { // we left n elements for the right sum 
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if(maxHeap.size() > n) { // if we take sum of more then n element then subtract maximum element to get minimum sum
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }

            leftMinSum[i] = leftSum;
        }


        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        for(int i = N-1; i >= n; i--) { // we left n elements for the left sum 
            minHeap.push(nums[i]);
            rightSum += nums[i];

            if(minHeap.size() > n) { // if we take sum of more then n element then subtract minimum element to get maximum sum
                rightSum -= minHeap.top();
                minHeap.pop();
            }

            rightMaxSum[i] = rightSum;
        }


        long long result = LLONG_MAX;

        for(int i = n-1; i <= 2*n-1; i++) {
            result = min(result, leftMinSum[i] - rightMaxSum[i+1]);
        }

        return result;

    }
};
// to get  the minimum difference possible between the sums of the two parts after the removal of n elements.:
// minimize the left sum and maximize right sum.
// to minimize left sum not consider maximum element in the left sum(use max-heap) and
// to maximize right sum not consider minimun element in the right sum(use min-heap)