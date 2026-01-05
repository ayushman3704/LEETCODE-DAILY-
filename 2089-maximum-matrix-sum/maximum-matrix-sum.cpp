class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0;
        int cntNegative = 0;
        int minabs = INT_MAX;

        for(auto rows : matrix){
            for(int i : rows){
                if(i < 0)
                cntNegative++;

                ans += abs(i);

                minabs = min(minabs, abs(i));
            }
        }

        if(cntNegative % 2 == 0)
        return ans;

        return ans - (2ll*minabs);
    }
};

