class Solution { // four pointer approach.
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int down = m-1;

        int left = 0;
        int right = n-1;

        int dir = 0;

        vector<int> res;

        while(top <= down && left <= right){
            if(dir == 0){ // print left to right. row (top) will be constant
                for(int i = left; i <= right; i++){
                    res.push_back(matrix[top][i]);
                }
                top++; // move row(top) one row down
            }

            if(dir == 1){ // print top to down. right most col(right) will be constant
                for(int i = top; i <= down; i++){
                    res.push_back(matrix[i][right]);
                }
                right--; // move rightmost col(right) one col left
            }

            if(dir == 2){ // print right to left. bottom most row(down) will be constant
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[down][i]);
                }
                down--; // move bottom most row(down) one row up
            }

            if(dir == 3){ // print down to top. left most col(left) will be constant.
                for(int i = down; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++; // move left most col(left) one col right
            }

            dir++; // increase direction 

            if(dir == 4) // if direction is 4 means more than 3 then reset dir to 0
            dir = 0;
        }

        return res;
    }
};