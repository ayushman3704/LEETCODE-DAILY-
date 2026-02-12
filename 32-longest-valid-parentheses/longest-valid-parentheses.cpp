class Solution { // using stack. Better approach
public:
    int longestValidParentheses(string s) {
        
        stack<int> st; // stack to store indices of (
        st.push(-1);  // base index for first valid substring

        int maxlen = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '('){
                st.push(i);
            }

            else{   // s[i] == ')'
                st.pop();

                if(st.empty()) // invalid ')', set new base
                st.push(i);

                else{   // valid substring length
                    maxlen = max(maxlen, i-st.top());
                }
            }
        }
        return maxlen;
    }
};