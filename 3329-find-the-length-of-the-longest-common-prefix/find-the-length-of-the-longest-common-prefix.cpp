class Solution {    // store all prefixes from arr1, then query arr2
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;

        // Store prefixes from arr1
        for(int num : arr1){

            while(num > 0){

                st.insert(num);
                num /= 10;
            }
        }
        
        int ans = 0;
        // Check arr2
        for(int num : arr2){

            while(num > 0){

                if(st.count(num)){

                    int len = to_string(num).length();
                    ans = max(ans, len);
                }

                num /= 10;
            }

        }

        return ans;
    }
};