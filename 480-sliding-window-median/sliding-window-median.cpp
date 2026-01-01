class Solution { // Optimal Approach- "Two Heaps + Lazy Deletion"
public:
    // Max heap for smaller half
    priority_queue<long long> left;
    // Min heap for larger half
    priority_queue<long long, vector<long long>, greater<long long>> right;

    // Lazy deletion map
    unordered_map<long long, int> delayed;

    int leftSize = 0;   // valid elements in left heap
    int rightSize = 0;  // valid elements in right heap
    int k;

    // Remove invalid elements from heap top
    void cleanTop(priority_queue<long long> &heap) {
        while (!heap.empty()) {
            long long x = heap.top();
            if (delayed.count(x) && delayed[x] > 0) {
                delayed[x]--;
                if (delayed[x] == 0) delayed.erase(x);
                heap.pop();
            } else break;
        }
    }

    void cleanTop(priority_queue<long long, vector<long long>, greater<long long>> &heap) {
        while (!heap.empty()) {
            long long x = heap.top();
            if (delayed.count(x) && delayed[x] > 0) {
                delayed[x]--;
                if (delayed[x] == 0) delayed.erase(x);
                heap.pop();
            } else break;
        }
    }

    // Balance the two heaps
    void rebalance() {
        // left can have at most one extra element
        if (leftSize > rightSize + 1) {
            right.push(left.top());
            left.pop();
            leftSize--;
            rightSize++;
            cleanTop(left);
        } 
        else if (leftSize < rightSize) {
            left.push(right.top());
            right.pop();
            rightSize--;
            leftSize++;
            cleanTop(right);
        }
    }

    void addNum(long long num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
            leftSize++;
        } else {
            right.push(num);
            rightSize++;
        }
        rebalance();
    }

    void removeNum(long long num) {
        delayed[num]++;

        if (num <= left.top()) {
            leftSize--;
            if (num == left.top()) cleanTop(left);
        } else {
            rightSize--;
            if (!right.empty() && num == right.top()) cleanTop(right);
        }
        rebalance();
    }

    double getMedian() {
        if (k % 2 == 1) {
            return (double)left.top();
        } else {
            return ((double)left.top() + (double)right.top()) / 2.0;
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        vector<double> ans;

        // Build first window
        for (int i = 0; i < k; i++) {
            addNum(nums[i]);
        }
        ans.push_back(getMedian());

        // Slide window
        for (int i = k; i < nums.size(); i++) {
            addNum(nums[i]);
            removeNum(nums[i - k]);
            ans.push_back(getMedian());
        }

        return ans;
    }
};