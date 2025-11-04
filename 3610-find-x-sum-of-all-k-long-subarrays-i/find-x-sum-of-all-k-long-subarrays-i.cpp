class Solution { // min-heap + sliding window
public:
    typedef pair<int, int> p;

    int topXSum(unordered_map<int, int> &mp, int x){ // function to calculate sum to top x frequent element

        priority_queue<p, vector<p>, greater<p>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first}); // put higher frequecy at top

            if(pq.size() > x)
            pq.pop();
        }

        int sum = 0;

        while(!pq.empty()){
            auto pair = pq.top();
            pq.pop();

            sum += pair.first*pair.second; // calculate sum (element * frequency)
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;

        vector<int> res;

        int i = 0;
        int j = 0;

        while(j < nums.size()){ // khandani sliding window template
            mp[nums[j]]++;

            if(j-i+1 == k){
                res.push_back(topXSum(mp, x));

                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};