class Solution { // BFS (State - space BFS). 
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> st(deadends.begin(), deadends.end());

        if(st.count("0000")) return -1;

        queue<pair<string, int>> q;

        unordered_set<string> visited;

        q.push({"0000", 0});

        visited.insert("0000");

        while(!q.empty()){

            string curr = q.front().first;
            int step = q.front().second;

            q.pop();

            if(curr == target) 
            return step;

            for(int i = 0; i < 4; i++){

                string temp = curr;
                
                // forword move
                temp[i] = (curr[i] - '0' + 1) % 10 + '0';
                if(!st.count(temp) && !visited.count(temp)){

                    q.push({temp, step + 1});
                    visited.insert(temp);
                }

                temp = curr;
                // backword move
                temp[i] = (curr[i] - '0' + 9) % 10 + '0';
                if(!st.count(temp) && !visited.count(temp)){

                    q.push({temp, step + 1});
                    visited.insert(temp);
                }
            }
        }

        return -1;
    }
};