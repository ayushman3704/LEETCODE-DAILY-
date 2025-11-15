//Approach (Improving the brute force by skipping index j wherever possible)
//T.C : Worst case O(n^2), but since we skip indices we get O(n*sqrt(n))
//S.C : O(n)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCount1(n, 0);
        cumCount1[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCount1[i] = cumCount1[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        //[i...j] = cumCount1[j] - cumCount1[i-1];

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int count1  = cumCount1[j] - (i - 1 >= 0 ? cumCount1[i-1] : 0);
                int count0 = (j - i + 1) - count1;

                if((count0 * count0) > count1) {
                    //skip j to avoid waste indices
                    int wasteIndices = (count0 * count0) - count1;
                    j += wasteIndices - 1;
                } else if((count0 * count0) == count1) {
                    res += 1;
                } else { //(zeroCount * zeroCount) < oneCount
                    //[i....j] is a valid substring
                    res += 1;

                    //try to see how much j can shift to right until substring remains dominant
                    int k = sqrt(count1) - count0;
                    int nextj = j + k;

                    if(nextj >= n) { //out of bound, means all indices are valid
                        res += (n - j - 1);
                        break; //early break
                    } else {
                        res += k;
                    }

                    j = nextj;
                }
            }
        }

        return res;
    }
};