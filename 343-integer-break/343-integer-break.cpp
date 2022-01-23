class Solution {
public:
    int integerBreak(int n) {
        vector<int> res(n+1, 1);
        res[0]=0;
        int i, j, temp;
        for(i=2; i<=n; ++i){
            for(j=1; j<=i/2; ++j){
                temp = max(max(j*res[i-j], j*(i-j)), max(res[j]*(i-j), res[j]*res[i-j]));
                res[i]=max(res[i], temp);
            }
        }
        return res[n];
    }
};