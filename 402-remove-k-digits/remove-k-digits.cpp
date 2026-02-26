class Solution { // stack as state machine
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;

        for(char d : num){

            // Stack maintains increasing order (monotonic increasing)
            // Stack holds smallest possible prefix so far
            while(!st.empty() && k > 0 && st.top() > d){
                st.pop();
                k--;
            }
            st.push(d);
        }

        // If removals still left, remove from end (largest digits)
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        // Build result string
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int ind = 0;
        while(ind < res.size() && res[ind] == '0') ind++;

        res = res.substr(ind);

        return res.empty() ? "0" : res;
    }
};