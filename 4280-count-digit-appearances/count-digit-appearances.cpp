class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int n = nums.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            
            int num = nums[i];

            while(num){

                int d = num % 10;

                if(d == digit)
                ans++;

                num /= 10;
            }
        }

        return ans;
    }
};