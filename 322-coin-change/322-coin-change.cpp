class Solution {
public:
    int memo(vector<int>& coins, int amount, int items, vector<vector<int>> &res){
        if(items==0 && amount==0){
            return res[items][amount] = 0;
        } 
        if(items==0 && amount!=0){
            return res[items][amount] = -1;
        }
        if(amount==0){
            return res[items][amount] = 0;
        }
        if(res[items][amount]!=-2){
            return res[items][amount];
        }
        if(coins[items-1]>amount){
            return res[items][amount] = memo(coins, amount, items-1, res);
        }else{
            int a = memo(coins, amount, items-1, res);
            int b = memo(coins, amount-coins[items-1], items, res);
            if(a==-1 && b==-1){
                return res[items][amount] = -1;
            }
            if(a==-1){
                return res[items][amount] = b+1;
            }
            if(b==-1){
                return res[items][amount] = a;
            }
            return res[items][amount] = min(a, b+1);
        }
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> res(n+1, vector<int>(amount+1, -2));
        memo(coins, amount, n, res);
        return res[n][amount];
    }
};