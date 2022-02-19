class Solution {
public:
    int tribonacci(int n) {
        vector<int> series(38+1, 0);
        series[0]=0;
        series[1]=1;
        series[2]=1;
        
        for(int i=3; i<=n; ++i){
            series[i]=series[i-1]+series[i-2]+series[i-3];
        }
        
        return series[n];
    }
};