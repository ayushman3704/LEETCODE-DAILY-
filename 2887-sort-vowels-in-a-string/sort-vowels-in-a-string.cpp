class Solution { // Approach-2. 
public:
    bool isVowel(char ch){
        ch = tolower(ch);

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        unordered_map<char, int> freq; 

        for(char ch : s){
            if(isVowel(ch)) // if vowel in original string then store in the freq map with the frequency of that vowel
            freq[ch]++;
        }

        string temp;
        temp = "AEIOUaeiou";
        int j = 0;

        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                while(freq[temp[j]] == 0){ // temp vowel is not present in freq map means the vowel is not in original string. so increment j pointer
                    j++;
                }
            // else
                s[i] = temp[j];
                freq[s[i]]--;
            }
        }
        return s;
    }
};