class Solution { // two pass solution
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;

        for(int &num : nums) { // first store all elements and it's corresponding frequency into the right map
            mp_right[num]++;
        }

        for(int &num : nums) {
            mp_right[num]--; // decrease the frequency from the right map and increase the frequency into left map

            int left  = mp_left[num*2]; // find if nums*2 is present into the left map
            int right = mp_right[num*2]; // find it nums*2 is present into the right map

            result = (result + (1LL * left * right)) % M; // count all valid triplets

            mp_left[num]++; // increase (update) frequency into left map
        }

        return result;
    }
};