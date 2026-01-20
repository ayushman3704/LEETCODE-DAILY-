class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();

        int lessCnt = 0;
        int equalCnt = 0;

        for(int x : nums){
            if(x < pivot)
            lessCnt++;

            else if(x == pivot)
            equalCnt++;
        }

        vector<int> res(n);

        int less = 0;
        int equal = lessCnt;
        int greater = lessCnt + equalCnt;

        for(int x : nums){
            if(x < pivot){
                res[less++] = x;
            }else if(x == pivot){
                res[equal++] = x;
            }else {
                res[greater++] = x;
            }
        }

        return res;
    }
};