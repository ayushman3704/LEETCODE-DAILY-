class Solution { // bottom up appraoch
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int> t(n, 0);
        
        for(int i = n-1; i >= 0; i--){
            if(i+k < n){
                t[i] = energy[i] + t[i+k];
            }else{
                t[i] = energy[i];
            }
        }

        return *max_element(t.begin(), t.end());
    }
};