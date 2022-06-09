class Solution {
public:
    bool rec(vector<int>& arr, int start, vector<bool> visited){
        if(arr[start]==0){
            return true;
        }
        visited[start]=true;
        int n = start+arr[start], p = start-arr[start];
        if((n<arr.size() and !visited[n]) and rec(arr, n, visited)) return true;
        if((p>-1 and !visited[p]) and rec(arr, p, visited)) return true;
        return false;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return rec(arr, start, visited);
    }
};