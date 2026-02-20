class Solution { // using line sweap
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<vector<int>> events;

        // 1. Build events
        for(auto trip : trips){
            int p = trip[0];
            int f = trip[1];
            int t = trip[2];

            events.push_back({f, +p});
            events.push_back({t, -p});
            
        }

        sort(events.begin(), events.end()); // 2. Sort by position 

        // 3. sweep line
        int currPassangers = 0;
        for(auto event : events){

            currPassangers += event[1];

            if(currPassangers > capacity) return false;
        }
        return true;
    }
};