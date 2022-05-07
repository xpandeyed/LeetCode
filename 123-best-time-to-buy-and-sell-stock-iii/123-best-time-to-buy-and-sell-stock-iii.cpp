class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb=INT_MIN, sb=INT_MIN, fs=0, ss=0, i, n=prices.size();
        for(i=0; i<n; ++i){
            fb=max(fb, -prices[i]);
            fs=max(fs, fb+prices[i]);
            sb=max(sb, fs-prices[i]);
            ss=max(ss, sb+prices[i]);
        }
        return ss;
        
    }
};