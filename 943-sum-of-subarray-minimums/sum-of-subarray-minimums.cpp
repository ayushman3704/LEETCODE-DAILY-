class Solution { // using monotonic stack
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int> st; // stack to store indices
        int n = arr.size();

        vector<int> ple(n); // to store previous less element
        for(int i = 0; i < n; i++){ // Previous Less Element
            while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();

            ple[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty())
        st.pop();

        vector<int> nle(n); // to store next less element
        for(int i = n-1; i >= 0; i--){ // Next Less Element

            while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

            nle[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){ // Traverse arr and Find Number of subarrays where arr[i] is minimum
            long long left = i - ple[i];
            long long right = nle[i] - i;

            ans = (ans + arr[i]*left % MOD * right % MOD) % MOD;
        }
        return ans;
    }
};