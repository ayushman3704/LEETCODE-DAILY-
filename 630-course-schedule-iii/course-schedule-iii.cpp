class Solution { // using gready + heap. Pattern "PROFIT / DEADLINE SCHEDULING"
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // step-1 sort by lastDay in ascending order
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        // step-2  max heap of durations
        priority_queue<int> max;

        int totalTime = 0;

        for(auto &course : courses){
            int duration = course[0];
            int lastDay = course[1];

            // Try to take the course
            if(totalTime + duration <= lastDay){
                totalTime += duration;
                max.push(duration);
            }
            // Try replacement
            else if(!max.empty() && max.top() > duration){
                totalTime -= max.top();
                max.pop();

                totalTime += duration;
                max.push(duration);
            }
        }
        return max.size();
    }
};