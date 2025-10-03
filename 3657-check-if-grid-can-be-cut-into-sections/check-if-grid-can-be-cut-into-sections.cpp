class Solution { // this problem in like leetcode- 56
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { // copy and paste code from leetcode- 56. just change the if condition to stictly greater than
        int n = intervals.size();

        sort(begin(intervals), end(intervals)); // step- 1

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++){ // step- 2
            if(intervals[i][0] < res.back()[1]){ // intervals are overlapping so merge it
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else
            res.push_back(intervals[i]);
        }

        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor;
        vector<vector<int>> ver;

        for(auto & coord : rectangles){
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.push_back({x1, x2});
            ver.push_back({y1, y2});
        }

        vector<vector<int>> res1;
        vector<vector<int>> res2;

        res1 = merge(hor);
        res2 = merge(ver);

        return res1.size() >= 3 || res2.size() >= 3;
    }
};