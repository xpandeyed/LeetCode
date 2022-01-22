class Solution {
public:
    
    bool helper(int n, vector<int> results){
        if(n==0){
            return results[n] = false;
        }
        if(n==1){
            return results[n] = true;
        }
        if(results[n]!=-2){
            return results[n];
        }
        int last = sqrt(n);
        bool res = false;
        for(int i=1; i<=last; ++i){
            res |= (!winnerSquareGame(n-i*i));
            
            
        }
        return results[n] = res;
    }
    
    bool winnerSquareGame(int n) {
        vector<bool> results(n+1, false);
        results[0]=false;
        results[1]=true;
        for(int i=2; i<n+1; ++i){
            bool res = false;
            int last=sqrt(i);
            for(int j=1; j<=last; ++j){
                res |= (!results[i-j*j]);
                if(res){
                    results[i]=true;
                    break;
                }
            }
        }
        return results[n];
    }
};