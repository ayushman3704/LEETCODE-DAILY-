class Solution { // using monotonic stack
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nextGreater; // store {value, next greater value}

        stack<int> st; // store nums2 elements

        for(int num : nums2){

            while(!st.empty() && num > st.top()){
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){ // no next greater element is present store -1
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // finally, nextGreater has next greater elements of all elements of nums2. Push elements from nums2 into res
        vector<int> res; 
        for(int num : nums1){
            res.push_back(nextGreater[num]);
        }
        return res;
    }
};