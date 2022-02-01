class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minA[prices.size()];
        minA[0]=prices[0];
        for(int i=1; i<prices.size(); ++i){
            minA[i]=min(minA[i-1], prices[i]);
        }
        int maxA[prices.size()];
        maxA[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; --i){
            maxA[i]=max(maxA[i+1], prices[i]);
        }
        int res = 0;
        for(int i=0; i<prices.size(); ++i){
            if(res<maxA[i]-minA[i]){
                res=maxA[i]-minA[i];
            }
        }
        return res;
    }
};