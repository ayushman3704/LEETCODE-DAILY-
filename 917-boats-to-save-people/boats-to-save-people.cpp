class Solution { // Sorting + two pointer.
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();

        int boat = 0;

        sort(people.begin(), people.end());

        int left = 0; // pointer to lighlest weight people
        int right = n - 1; // pointer to heaviest weight people

        while(left <= right){

            if(people[left] + people[right] <= limit){
                left++;
                right--;
            }
            else{

                right--;
            }

            boat++;
        }

        // if(i < n){
        //     cnt++;
        // }

        return boat;
    }
};