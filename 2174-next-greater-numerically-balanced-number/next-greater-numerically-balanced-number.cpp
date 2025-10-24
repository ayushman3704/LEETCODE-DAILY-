class Solution { // using backtracking
public:
    vector<int> digitCount{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // vector that store count of each digit, means 0-> 0, 1-> 1, 2-> 2 and so on

    int backtracking(int num, int curr, int count){

        if(count == 0){ // base case
            for(int digit = 1; digit <= 9; digit++){ // case for balanced number strictly greater than num
                if(digitCount[digit] != 0 && digitCount[digit] != digit)
                return 0;
            }
            return curr > num ? curr : 0;
        }

        int result = 0;

        for(int digit = 1; digit <= 9; digit++){
            if(digitCount[digit] > 0 && digitCount[digit] <= count){
                digitCount[digit]--;
                result = backtracking(num, curr*10+digit, count-1);
                digitCount[digit]++;
            }

            if(result != 0)
            break;
        }
        return result;
    }
    
    int nextBeautifulNumber(int n) {
        
        int numDigit = to_string(n).length();

        int result = backtracking(n, 0, numDigit);

        if(result == 0)
        return backtracking(n, 0, numDigit+1);

        return result;
    }
};
// smallest numerically balanced number strictly greater than n. should be the same length of the num or just length + 1