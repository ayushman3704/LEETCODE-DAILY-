class Solution { // Using Gready Approach. (Fractional Knapsack Problem)
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0); // to store frequency of characters

        for(char &ch : tasks){
            mp[ch-'A']++;
        }

        sort(mp.begin(), mp.end());

        int maxFreq = mp[25]; // mp is sorted in increasing order so maximum frequency task will be at the end.
        int idleSlots = (maxFreq-1)*n; // no. of idle slots between max freq. charactor

        for(int i = 24; i >= 0; i--){ // schedule tasks in the decrease order of their frequecy
            idleSlots -= min(mp[i], maxFreq-1);
        }

        if(idleSlots > 0)
        return tasks.size() + idleSlots;

        return tasks.size();
    }
};