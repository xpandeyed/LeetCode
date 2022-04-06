class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size(), i, j, mod=1000000007, res=0, t;
        
        for(i=0;i<n; ++i){
            vector<int> freq(101, 0);
            for(j=i+1; j<n; ++j){
                t=target-arr[i]-arr[j];
                if(t>=0 and t<=100 and freq[t]>0){
                    res+=freq[t];
                    res%=mod;
                }
                freq[arr[j]]++;
            }
        }
        
        return res;
    }
};