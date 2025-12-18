class Solution { // using bfs
public:
    bool dfs(vector<int>& arr, int start, int n){
        if(start < 0 || start >= n || arr[start] < 0)
        return false;

        if(arr[start] == 0)
        return true;
        //I don't want to check start again in future
        //I could memoize it as well but making use of the fact
        //0 <= arr[i] < arr.length
        arr[start] = -arr[start];
		
        int left = dfs(arr, start-arr[start], n);
        int right = dfs(arr, start+arr[start], n);
        
        return left||right;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        return dfs(arr, start, n);
    }
};