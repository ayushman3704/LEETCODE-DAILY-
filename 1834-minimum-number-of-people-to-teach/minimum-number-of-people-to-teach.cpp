class Solution { // logical reasoning
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUser; // collections of those friends who can't talk

        for(auto friends : friendships){
            int u = friends[0] - 1; // convert this to 0 based indexing
            int v = friends[1] - 1; // convert this to 0 based indexing
            unordered_set<int> langSet(begin(languages[u]), end(languages[u])); // collections of all those languages which are spoked by the u

            bool canTalk = false;
            for(auto lang : languages[v]){ // check that the languages that are spoked by the v is spoked by the u, if any one of the languages is common in both means they are not sad user
                if(langSet.count(lang)){
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk){ // if they can't talk then they are sad user
                sadUser.insert(u);
                sadUser.insert(v);
            }
        }

        vector<int> language(n+1, 0); // collections of most speaked language by the sad user
        int mostKnownLang = 0; // count of most speaked language

        for(auto user : sadUser){
            for(auto lang : languages[user]){
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }
        return sadUser.size() - mostKnownLang; // minimum no. of people should we teach
    }
};