/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution { // using binary search
public:
    int guessNumber(int n) {
        int low = 1; 
        int high = n;

        while(high >= low){
            int guess_no = low + (high - low)/2;

            int val = guess(guess_no);

            if(val == 0)
            return guess_no;
            else if(val == -1)
            high = guess_no - 1;
            else
            low = guess_no + 1;
        }
        return 0;
    }
};