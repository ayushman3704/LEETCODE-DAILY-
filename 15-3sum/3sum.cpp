class Solution { // reduce to 2 sum 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            
            // skip duplicate i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1; 
            int r = n - 1;

            while(l < r){

                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});

                    // skip duplicate l
                    while(l < r && nums[l] == nums[l+1]) l++;

                    // skip duplicate r
                    while(l < r && nums[r] == nums[r-1]) r--;

                    l++;
                    r--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};