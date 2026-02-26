class Solution { // stack as state machine 
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int a : asteroids){

            bool destroyed = false;

            // Stack contains only asteroids that are still alive
            // Possible collision only when stack top > 0 and current < 0
            while(!st.empty() && st.top() > 0 && a < 0){

                if(abs(st.top()) < abs(a)){
                    // Stack top asteroid explodes
                    st.pop();
                    // Continue checking with next stack top
                }
                else if(abs(st.top()) == abs(a)){ // Both asteroids explode
                    st.pop();

                    destroyed = true;
                    break;
                }
                else{ // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            // If current asteroid survived all collisions
            if(!destroyed){
                st.push(a);
            }
        }

        // Convert stack to result
        vector<int> res(st.size());
        for(int i = res.size()-1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};