class Solution { // using min heap (optimal)
public:
    typedef pair<int, string> P;

    struct lambda{
        bool operator()(P &a, P &b){
            if(a.first != b.first){
            return a.first > b.first; // higher frequency first
        }

        return a.second < b.second; // lexicographically smaller first
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequency
        unordered_map<string, int> mp;

        for(string word : words){
            mp[word]++;
        }
        
        // Step 2: Min heap to keep ONLY top k words
        priority_queue<pair<int,string>,vector<pair<int,string>>,lambda> minHeap;

        // Step 3: Process each unique word
        for(auto &it: mp){
            // Push current word into heap
            minHeap.push({it.second, it.first});

            // If heap grows beyond k, remove the worst word
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        // Step 4: Extract elements from heap
        // Heap gives worst first, so reverse later
        vector<string> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);

            minHeap.pop();
        }

        // Step 5: Reverse to get correct order
        reverse(res.begin(), res.end());

        return res;
    }
};