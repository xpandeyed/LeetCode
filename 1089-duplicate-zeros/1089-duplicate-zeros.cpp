class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size(), j=n-1, i;
        for(int x: arr){
            if(!x){
                j++;
            }
        }
        
        for(i=n-1; i>-1; --i){
            if(arr[i]==0){
                if(j<n){
                    arr[j]=0;
                    j--;
                    arr[j]=0;
                    j--;
                }
                else{
                    j--;
                    if(j<n){
                        arr[j]=0;
                    }
                    j--;
                }
            }
            else{
                if(j<n){
                    arr[j]=arr[i];
                    j--;
                }else{
                    j--;
                }
            }
        }
    }
};