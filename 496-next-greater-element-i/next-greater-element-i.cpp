class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st; // stack to store indices 
        vector<int> nge(n, -1); // store next greater element at that index

        for(int i = 0; i < n; i++){   // Step 1: compute NGE for nums2
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                nge[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> res;
        for(int x : nums1){
            for(int i = 0; i < n; i++){
                if(nums2[i] == x){ // find index of x in nums2
                    res.push_back(nge[i]);
                }
            }
        }

        return res;
    }
};