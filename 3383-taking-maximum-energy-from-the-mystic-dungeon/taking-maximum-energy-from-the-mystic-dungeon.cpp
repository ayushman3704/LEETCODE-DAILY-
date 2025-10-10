class Solution { // recursion + memoization
public:

    int solve(vector<int>& energy, int i, int k, vector<int> &t){
        int n = energy.size();

        if(i >= n)
        return 0;

        if(t[i] != INT_MIN)
        return t[i];

        return t[i] = energy[i] + solve(energy, i+k, k, t);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int> t(n, INT_MIN);

        int maxEnergy = -1e9;
        
        for(int i = 0; i < n; i++){
            maxEnergy = max(maxEnergy, solve(energy, i, k, t));
        }

        return maxEnergy;
    }
};