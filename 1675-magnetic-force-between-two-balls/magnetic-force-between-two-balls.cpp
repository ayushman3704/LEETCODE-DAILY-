class Solution { // Similar Pattern as Aggressive cows
public:
    bool isPossible(vector<int>& position, int mid, int m){
        int count = 1;
        int lastPlaced = position[0];

        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastPlaced >= mid){
                count++;
                lastPlaced = position[i];
            }
            if(count >= m)
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        int res = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(position, mid, m)){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res;
    }
};