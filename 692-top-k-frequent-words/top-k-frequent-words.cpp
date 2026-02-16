class Solution { // Brute force using sorting.
public:
    // Comparator used for sorting
    // Higher frequency comes first
    // If frequency is same, lexicographically smaller word comes first
    static bool comparator(const pair<string, int> &a, const pair<string, int> &b){
        if(a.second != b.second){
            return a.second > b.second; // higher frequency first
        }

        return a.first < b.first; // lexicographically smaller first
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // Step 1: Count frequency of each word
        unordered_map<string, int> mp;

        for(string word : words){
            mp[word]++;
        }

        // Step 2: Store all (word, frequency) pairs
        vector<pair<string, int>> arr;

        for(auto it : mp){
            arr.push_back({it.first, it.second});
        }

        // Step 3: Sort all unique words
        sort(arr.begin(), arr.end(), comparator);

        // Step 4: Take first k words
        vector<string> result;
        for(int i = 0; i < k; i++){
            result.push_back(arr[i].first);
        }

        return result;
    }
};