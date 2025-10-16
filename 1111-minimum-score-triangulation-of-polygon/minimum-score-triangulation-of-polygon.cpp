class Solution { // recursion + memoization. similar to problem- 1547. Pattern- Interval DP
public:
    int t[51][51];
    int solve(vector<int>& values, int l, int r){
        if(r-l < 2)
        return 0;

        if(t[l][r] != -1)
        return t[l][r];

        int res = INT_MAX;

        for(int k = l+1; k <= r-1; k++){
            int score = values[l]*values[k]*values[r] + solve(values, l, k) + solve(values, k, r);

            res = min(res, score); 
        }
        return t[l][r] = res;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(t, -1, sizeof(t));
 
        return solve(values, 0, values.size()-1);
    }
};