class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0;
        
        while(numBottles >= numExchange){
            drink += numExchange;
            numBottles -= numExchange;

            numBottles ++;
        }
        drink += numBottles;

        return drink;
    }
};