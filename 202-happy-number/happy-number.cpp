class Solution { // using fast and slow pointer.
public:
    // Helper function: computes the next number
    // by summing squares of digits of x
    int nextNum(int x){
        int sum = 0;

        // Process each digit
        while(x > 0){
            int digit = x % 10; // extract last digit
            sum += digit*digit; // add square
            x = x/10; // remove last digit
        }
        return sum;
    }
    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;

        do{
            slow = nextNum(slow); // 1 transformation
            fast = nextNum(nextNum(fast)); // 2 transformation
        }while(slow != fast);

        if(slow == 1)
        return true;

        return false;
    }
};