class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        
        int n = capacity.size();

        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++){
            temp.push_back({capacity[i], i});
        }

        sort(temp.begin(), temp.end());

        for(auto it : temp){

            if(it.first >= itemSize){
                return it.second;
            }
        }

        return -1;
    }
};