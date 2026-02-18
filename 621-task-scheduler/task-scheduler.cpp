class Solution { // using max Heap
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Step 1: Count frequency of each task
        // There are only 26 possible tasks (A to Z)
        vector<int> freq(26, 0);

        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        // Step 2: Max Heap to always pick the task
        // with highest remaining frequency
        priority_queue<int> pq;

        for(int f : freq){
            if(f > 0){
                pq.push(f);
            }
        }

        // Step 3: Queue to manage cooldown
        // Each element: {remaining_frequency, time_when_task_is_available}
        queue<pair<int, int>> coolDown;

        int currTime = 0;

        while(!pq.empty() || !coolDown.empty()){

            currTime++;

            // release ALL tasks whose cooldown expired and push into max-heap
            if(!coolDown.empty() && coolDown.front().second <= currTime){
                pq.push(coolDown.front().first);

                coolDown.pop();
            }

            // If there is an available task, execute it
            if(!pq.empty()){
                
                // Pick the task with highest remaining frequency
                int currFreq = pq.top();
                pq.pop();

                currFreq--; // execute the task and decrease frequency

                if(currFreq > 0){ // if task frequency is remaining then push it into coolDown queue
                    coolDown.push({currFreq, currTime + n + 1});
                }
            }
        }
        return currTime;
    }
};