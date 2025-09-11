class Solution { // Approach-1. 
                // 1. make string of all vowels and sort the string of vowels. 
                // 2. Traverse in original string(s) and if vowel is encountered in original string then replace with vowel present in vowel string(temp)
public:
    bool isVowel(char ch){
        ch = tolower(ch);

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        string temp;

        for(char ch : s){
            if(isVowel(ch))
            temp.push_back(ch);
        }

        sort(temp.begin(), temp.end());
        int j = 0;

        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};