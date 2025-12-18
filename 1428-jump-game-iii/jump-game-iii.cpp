class Solution { // using bfs
public:
    bool bfs(vector<int>& arr, int start, int n){
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0)
            return true;

            if(arr[curr] < 0) // if element is visited, continue
            continue;

            int left = curr - arr[curr];
            int right = curr + arr[curr];

            if(left >= 0 && left < n){
                q.push(left);
            }
            if(right >= 0 && right < n){
                q.push(right);
            }

            arr[curr] = -arr[curr]; // mark that element visited
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        return bfs(arr, start, n);
    }
};