class Solution {
public:
    int dynamic(int n){
        if(n<=3){
            return n;
        }

        vector<int> res(n+1, INT_MAX);

        res[0]=0;
        res[1]=1;
        res[2]=2;
        res[3]=3;

        int i, root, j;
        for(i=4; i<=n; ++i){
            root=(int)sqrt(i);
            for(j=1; j<=root; ++j){
                res[i]=min(res[i], 1+(res[i-j*j]));
            }
        }
        
        return res[n];
    }
    
    int numSquares(int n) {
        return dynamic(n);
    }
};