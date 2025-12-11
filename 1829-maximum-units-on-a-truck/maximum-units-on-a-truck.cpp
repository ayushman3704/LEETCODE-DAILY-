class Solution { // using Fractional Knapsack (Greedy Algorithm).
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), compare);

        int res = 0; 
        int currSize = truckSize;

        for(auto it : boxTypes){
            if(it[0] <= currSize){
                res += it[1]*it[0];

                currSize -= it[0];
            }else{
                res += (it[1]*currSize);

                break;
            }
        }
        return res;
    }
};