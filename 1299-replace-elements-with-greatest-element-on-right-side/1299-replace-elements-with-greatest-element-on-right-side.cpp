class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int i, n=arr.size(), maxSoFar=arr[n-1], curr;
        arr[n-1]=-1;
        
        for(i=n-2; i>-1; --i){
            curr = arr[i];
            arr[i]=maxSoFar;
            maxSoFar = max(maxSoFar, curr);
        }
        
        return arr;
    }
};