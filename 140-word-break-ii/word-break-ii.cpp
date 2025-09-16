class Solution { // backtracking
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string& currSentence, string &s) {
        if(i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.length(); j++) {

            string tempWord = s.substr(i, j-i+1);

            if(dict.find(tempWord) != dict.end()) { // if tempWord is present in dict
                string origSentence = currSentence;
                if(!currSentence.empty())
                    currSentence += " ";
                
                currSentence += tempWord;

                solve(j+1, currSentence, s);

                currSentence = origSentence; // backtrack

            }

        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) { // store wordDict into dict set
            dict.insert(word);
        }

        string currSentence = "";
        solve(0, currSentence, s);

        return result;
    }
};