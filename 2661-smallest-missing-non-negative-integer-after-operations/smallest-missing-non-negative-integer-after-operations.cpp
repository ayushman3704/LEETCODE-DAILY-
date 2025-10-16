class Solution { // using simple maths and modulo
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        for(int & num : nums){
            int r = ((num % value) + value) % value; // calculate modulo to handle negative number

            mp[r]++;
        }

        int MEX = 0;

        while(mp[(MEX % value)] > 0){
            mp[(MEX % value)]--;

            MEX++;
        }
        return MEX;
    }
};