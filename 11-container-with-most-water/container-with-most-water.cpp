class Solution { // two pointer approach. 
                //  maximum amount of water a container can store where the area is maximum.
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0, j = n - 1;

        int maxWater = 0;

        while(i < j){
            int w = j - i;
            int h = min(height[i], height[j]);

            int area = w*h;

            maxWater = max(maxWater, area); // update maxWater 

            // when we move pointers then width will decrease, so to maximize area we need to maximize height. in order to maximize height we move the minimum height pointer. 
            if(height[i] > height[j]) 
            j--;
            else
            i++;
        }

        return maxWater;
    }
};