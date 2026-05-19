class Solution { // Brute Force. Simulation
public:
    int compareBitonicSums(vector<int>& nums) {
        
        // long long sum = accumulate(nums.begin(), nums.end(), 0);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];
        }

        int peakIndex = -1;

        long long leftPart = 0;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i-1] < nums[i]){

                leftPart += nums[i-1];
            }else{

                leftPart += nums[i-1];

                peakIndex = i-1;
                break;
            }
        }

        long long rightPart = sum - leftPart + nums[peakIndex];

        if(leftPart == rightPart)  return -1;
        if(leftPart > rightPart) return 0;
        
        return 1;
    }
};