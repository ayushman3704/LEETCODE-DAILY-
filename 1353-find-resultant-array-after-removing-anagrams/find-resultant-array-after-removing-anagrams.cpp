class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> temp(n);

        for(int i = 0; i < n; i++){
            string word = words[i];

            sort(begin(word), end(word));
            temp[i] = word;
        }

        vector<string> res;
        res.push_back(words[0]);

        for(int i = 1; i < n; i++){
            if(temp[i-1] == temp[i]){
                continue;
            }else{
                res.push_back(words[i]);
            }
        }
        return res;
    }
};