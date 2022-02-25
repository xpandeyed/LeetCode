class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size(), res=0, i, ma=values[0];
        for(i=1; i<n; ++i){
            res=max(res, ma+values[i]-i);
            ma=max(values[i]+i, ma);
        }
        return res;
    }
};