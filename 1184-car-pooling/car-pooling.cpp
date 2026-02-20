class Solution { // using difference array technique(used for small range)
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> diff(1001, 0);

        // 1. Mark changes
        for(auto trip : trips){
            int p = trip[0];
            int f = trip[1];
            int t = trip[2];

            diff[f] += p;
            diff[t] -= p;
            
        }

        // 2. Prefix sum + validation
        int currPassangers = 0;
        for(int i = 0; i < diff.size(); i++){

            currPassangers += diff[i];

            if(currPassangers > capacity) return false;
        }
        return true;
    }
};