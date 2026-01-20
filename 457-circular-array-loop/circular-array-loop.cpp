class Solution {
public:
    int nextIndex(int i, vector<int> &nums){
        int n = nums.size();

        return ((i + nums[i])%n + n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){ // Try Every Index as a Start because a cycle can start from anywhere
            
            if(nums[i] == 0) // This index is already known to be invalid, no need to reprocess
            continue;

            int slow = i; // moves 1 step
            int fast = i; // moves 2 steps

            bool dir = nums[i] > 0; // dir = + means forward only and dir = - means backward only

            while(true){
                // ---- validate slow edge ----
                int nextSlow = nextIndex(slow, nums);
                if ((nums[slow] > 0) != dir) break;
                if (nextSlow == slow) break;   // self-loop

                // ---- validate fast first edge ----
                int nextFast = nextIndex(fast, nums);
                if ((nums[fast] > 0) != dir) break;
                if (nextFast == fast) break;

                // ---- validate fast second edge ----
                int nextFast2 = nextIndex(nextFast, nums);
                if ((nums[nextFast] > 0) != dir) break;
                if (nextFast2 == nextFast) break;

                slow = nextSlow;
                fast = nextFast2;

                if(slow == fast) // if they meet means valid cylce exits
                return true;
            }

            // Mark intire failed path as invalid to ensure we never reprocess it.
            int j = i;
            while(nums[j] != 0 && (nums[j] > 0) == dir){
                int nxt = nextIndex(j, nums);
                nums[j] = 0;
                j = nxt;
            }
        }
        return false;
    }
};