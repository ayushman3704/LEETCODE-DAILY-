class Solution { // using backtracking.  take, not take
public:
    int result = INT_MIN;
    void solve(vector<vector<int>>& requests, int ind, int count, vector<int> &resultant){
        if(ind >= requests.size()){ // base case
            bool allZero = true;
            for(auto &x: resultant){
                if(x != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero == true){
                result = max(result, count);
            }
            return;
        }

        int from = requests[ind][0]; 
        int to = requests[ind][1];
        resultant[from]--; // employee is leaving this building
        resultant[to]++; // employee is entering in this building

        solve(requests, ind+1, count+1, resultant);
        
        // backtrack
        resultant[from]++; 
        resultant[to]--;

        solve(requests, ind+1, count, resultant);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int count = 0;
        int ind = 0;
        vector<int> resultant(n, 0);

        solve(requests, ind, count, resultant);

        return result;
    }
};