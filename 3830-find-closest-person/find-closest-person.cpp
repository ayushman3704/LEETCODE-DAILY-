class Solution { // simple observation
public:
    int findClosest(int x, int y, int z) {
        int absDiff_x = abs(z - x);
        int absDiff_y = abs(z - y);

        if(absDiff_x < absDiff_y) 
        return 1;
        else if(absDiff_x > absDiff_y)
        return 2;

        return 0;
    }
};