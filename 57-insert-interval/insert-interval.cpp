class Solution { // pattern- interval overlapping. Do dry run of example-2 to understand the code
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();

        vector<vector<int>> res;

        while(i < n){
            if(intervals[i][1] < newInterval[0]){ // non-overlapping interval and less than newInterval means newInterval come after this interval
                res.push_back(intervals[i]);
            }else if(intervals[i][0] > newInterval[1]){ // non-overlapping interval and greater than newInterval so push newInterval here
                break;
            }else{ // intervals and newInterval are overlapping so merge them 
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            i++;
        }

        res.push_back(newInterval);

        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};