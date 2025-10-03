class Solution { // pattern- "merge intervals".
                // 1. sorting based on the starting point
                // 2. merge if intervals are overlapping
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals)); // step- 1

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++){ // step- 2
            if(intervals[i][0] <= res.back()[1]){ // intervals are overlapping so merge it
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else
            res.push_back(intervals[i]);
        }

        return res;
    }
};