class Solution {
public:
    
    int helper(int n, vector<int> &results){
        if(n==1){
            return results[1] = 1;
        }
        if(results[n]!=-1){
            return results[n];
        }
        int res , i ;
        res=n-1;
        for(i=2; i<=n/2; ++i){
            int res1 = i*(n-i);
            int res2 = i*helper(n-i, results);
            int res3 = helper(i, results)*(n-i);
            res = max(res, max(res1, max(res2, res3)));
        }
        return results[n] = res;
        
    }
    
    
    int integerBreak(int n) {
        vector<int> res(n+1, -1);
        helper(n, res);
        return res[n];
    }
};