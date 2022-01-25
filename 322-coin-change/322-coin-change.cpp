class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            int n=coins.size(), i, j, a, b;
    vector<vector<int>> res(n+1, vector<int>(amount+1, -1));
    for(i=0; i<n+1; ++i){
        for(j=0; j<amount+1; ++j){
            if(j==0){
                res[i][j]=0;
                continue;
            }
            if(i==0){
                res[i][j]=-1;
                continue;
            }
            if(coins[i-1]>j){
                res[i][j]=res[i-1][j];
            }else{
                a = res[i-1][j];
                b = res[i][j-coins[i-1]];
                if(a==-1 && b==-1){
                    res[i][j]=-1;
                    continue;
                }
                if(a!=-1 && b==-1){
                    res[i][j]=a;
                    continue;
                }
                if(a==-1 && b!=-1){
                    res[i][j]=(b+1);
                    continue;
                }
                if(a!=-1 && b!=-1){
                    res[i][j] = min(a, b+1);
                }
            }
        }
    }
    return res[n][amount];
    }
};