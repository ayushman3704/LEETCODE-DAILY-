class Solution { // stack as state machine
public:
    string decodeString(string s) {
        
        stack<pair<string, int>> st;

        string currStr = "";
        int currNum = 0;

        for(char ch : s){

            // Case 1: Digit
            if(isdigit(ch)){
                currNum = currNum*10 + (ch-'0');
            }

            // Case 2: Opening bracket '['
            else if(ch == '['){
                st.push({currStr, currNum});

                currStr = "";
                currNum = 0;
            }

            // Case 3: Closing bracket ']'
            else if(ch == ']'){
                auto[prevStr, prevNum] = st.top();
                st.pop();

                string expand = "";
                for(int i = 0; i < prevNum; i++){
                    expand += currStr;
                }
                currStr = prevStr + expand;
            }
            // Case 4: Alphabet character
            else{
                currStr += ch;
            }
        }
        return currStr;
    }
};