class Solution { // using binary search
public:
    int lowerBound(int l, int r, vector<int>& potions, int minPotion){
        int possibleInd = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(potions[mid] >= minPotion){
                possibleInd = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return possibleInd;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        // set<long long> st;
        vector<int> pairs;

        sort(begin(potions), end(potions));

        int maxPotion = potions[m-1];

        for(int i = 0; i < n; i++){
            int spell = spells[i];

            long long minPotion = ceil((1.0*success)/spell);

            if(minPotion > maxPotion){
                pairs.push_back(0);
                continue;
            }

            int ind = lowerBound(0, m-1, potions, minPotion);

            int count = m - ind;

            pairs.push_back(count);
        }
        return pairs;
    }
};