class Solution { // same as LEETCODE- 435. Pattern- "Activity Selection / Interval Scheduling / Interval Greedy pattern."
public:
    static bool compare(vector<int> &a, vector<int> &b){ // sort in ascending order by their end point
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrowCnt = 1;

        sort(points.begin(), points.end(), compare);

        int end = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= end)
            continue;
            else{
                end = points[i][1];
               arrowCnt++;
            }
        }
        return arrowCnt;
    }
};

// Core Difference in LEETCODE 435 and 452 (1 line)

// 435: Count how many intervals to delete so that no intervals overlap.

// 452: Count how many groups of overlapping intervals exist, because each group needs one arrow.