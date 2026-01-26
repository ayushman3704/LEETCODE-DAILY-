class Solution { // using sorting
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int n = arr.size();

        sort(arr.begin(), arr.end());
        int mini = INT_MAX;

        for(int i = 0; i < n-1; i++){ // calculating minimum absolute difference 
            mini = min(mini, arr[i+1] - arr[i]);
        }

        vector<vector<int>> res;

        for(int i = 0; i < n-1; i++){ // storing pairs in ascending order 
            if(arr[i] + mini == arr[i+1]){
                res.push_back({arr[i], arr[i+1]});
            }
        }

        return res;
    }
};