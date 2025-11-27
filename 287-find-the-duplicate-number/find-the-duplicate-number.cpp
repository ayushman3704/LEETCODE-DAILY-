class Solution { // Pattern - Hashing / Frequency | Hint: Floyd tortoise-hare on index graph
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow]; // move by one step
        fast = nums[nums[fast]]; // move by two steps

        while(slow != fast){ // detect cycle 
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0]; // start from beigning
        while(slow != fast){ // find starting point of cycle (duplicate element)
            slow = nums[slow]; // move pointer by one step
            fast = nums[fast]; // move pointer by one step
        }
        return fast;
    }
};