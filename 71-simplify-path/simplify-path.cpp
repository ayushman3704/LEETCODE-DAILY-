class Solution { // stack as state machine
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        int i = 0;

        while(i < n){

            // Skip multiple slashes
            while(i < n && path[i] == '/') i++;

            if(i >= n) break;

            string dir = "";

            // Extract directory name
            while(i < n && path[i] != '/'){
                dir += path[i];
                i++;
            }
            
            // Case 1: Current directory → ignore
            if(dir == ".")
            continue;

            // Case 2: Parent directory
            else if(dir == ".."){
                // Stack contains only valid directory names
                // Popping moves one level up if possible
                if(!st.empty())
                st.pop();
            }
            // Case 3: Valid directory
            else{
                st.push(dir); // Push extends the canonical path
            }
        }

        // Build result from stack
        string res = ""; 
        while(!st.empty()){
            res = '/' + st.top() + res;
            st.pop();
        }
        // If stack was empty → root
        return res.empty() ? "/" : res;
    }
};