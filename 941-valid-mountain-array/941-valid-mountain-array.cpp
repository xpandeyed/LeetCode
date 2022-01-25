class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool isFalling = false;
        int n=arr.size(), i;
        if(n<3){
            return false;
        }
        if(arr[1]<=arr[0]){
            return false;
        }
        for(i=1; i<n; ++i){
            if(arr[i]==arr[i-1]){
                return false;
            }
            if(!isFalling && arr[i-1]<arr[i]){
                continue;
            }
            if(!isFalling && arr[i]<arr[i-1]){
                isFalling = true;
                continue;
            }
            if(isFalling && arr[i]>=arr[i-1]){
                return false;
            }
        }
        if(isFalling){
            return true;
        }
        return false;
    }
};