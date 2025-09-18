// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;

        while(l <= r){
            int is_bad = l + (r-l)/2;

            int bad = isBadVersion(is_bad);

            if(bad){
                r = is_bad - 1;
            }

            if(!bad){
                l = is_bad + 1;
            }
        }
        return l;
    }
};