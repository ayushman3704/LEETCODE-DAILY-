class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;

        for(auto num : nums){
            while(!res.empty()){
                int prev = res.back();
                int curr = num;

                int GCD = gcd(curr, prev); // take gcd of curr and prev 
                if(GCD == 1) // means coprime number
                break;

                res.pop_back(); // if non coprime then replace that number
                int LCM = prev/GCD * curr; // find lcm

                num = LCM; // replace num with lcm
            }
            res.push_back(num); // push into res
        }
        return res;
    }
};