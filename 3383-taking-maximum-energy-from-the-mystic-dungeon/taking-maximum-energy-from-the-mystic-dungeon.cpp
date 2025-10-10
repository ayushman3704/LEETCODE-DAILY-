class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        int maxSum = -1e9;

        int sum = 0;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(vis[i] == 1)
            continue;
        

            int j = i;
            sum = 0;

            while(j < n){
                vis[j] = 1;

                sum += energy[j];

                sum = max(sum, energy[j]);

                j += k;
            }

            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};