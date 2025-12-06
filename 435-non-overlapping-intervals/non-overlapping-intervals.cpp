// bool compare(vector<int> &a, vector<int> &b){
//     return a[1] < b[1];
// }
class Solution { // sort in ascending order by their end value
public:
    // static bool compare(vector<int> &a, vector<int> &b){
    //     return a[1] < b[1];
    // }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b){
                return a[1] < b[1];
            }
        );

        int end = intervals[0][1]; // it store the end of the last or previous interval
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < end) // if any interval start before the end of previous interval then it is overlapping interval
            cnt++;
            else
            end = intervals[i][1]; // update the end 
        }
        return cnt;
    }
};