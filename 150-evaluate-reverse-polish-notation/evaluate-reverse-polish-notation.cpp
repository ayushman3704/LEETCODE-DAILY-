// In postfix notation:
// 1. Operator always works on last two unresolved operands
// 2. Once an operand is used, it will never be needed again

class Solution { // using stack. Reverse Polish Notation means postfix notation
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int n = tokens.size();

        // Number → push it
        // Operator → pop two numbers, apply operator, push result
        for(string &token : tokens){ 

            if(token == "+" || token == "-" ||token == "*" || token == "/"){
                
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();

                int res;

                if(token == "+"){
                    res = a + b;
                }else if(token == "-"){
                    res = a - b;
                }else if(token == "*"){
                    res = a * b;
                }else{
                    res = a / b;
                }

                st.push(res);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};