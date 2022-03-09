class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), i, j, temp, ma=0;
        
        vector<int> profits(n, 0);
        for(i=n-2; i>-1; --i){
            for(j=i+1; j<n; ++j){
                temp=0;
                if(j+2<n){
                    temp=profits[j+2];
                }
                
                profits[i] = max(profits[i], (prices[j]-prices[i])+temp);
                
            }
            profits[i]=max(profits[i], profits[i+1]);
            ma =max(ma, profits[i]);
        }
        
        // for(auto x: profits){
        //     cout << x << " ";
        // }
        // cout << endl;
        return ma;
    }
};