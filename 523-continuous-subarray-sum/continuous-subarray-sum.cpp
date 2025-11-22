class Solution { // modulo ki jai ho. Pattern - "Prefix Sum / Subarray. Hint: Prefix mod k set of earliest index"
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int, int> mp; // store {remender, imdex}
        mp[0] = -1; // cornner case 
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int remender = sum % k;

            if(mp.find(remender) != mp.end()){ // if remender is already present in the map means added number is divisible by k

                if(i - mp[remender] >= 2) // check size of subarray
                return true;
            }else{
                mp[remender] = i;
            }
        }
        return false;
    }
};

// if number % k = remender and
// (number + a) % k = remender 
// then a is definitely divisible by k means a % k = 0