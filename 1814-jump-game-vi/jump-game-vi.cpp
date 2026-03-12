class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> pq;

        int score = nums[0];

        pq.push({score, 0});

        for(int i = 1; i < nums.size(); i++){

            while(pq.top().second < i-k){
                pq.pop();
            }

            score = nums[i] + pq.top().first;

            pq.push({score, i});
        }

        return score;
    }
};