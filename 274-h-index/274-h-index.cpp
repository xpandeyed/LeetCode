class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(), i ,res=INT_MIN;
        sort(citations.begin(), citations.end(), greater<int>());
        for(i=0; i<n;++i){
            res = max(res, min(i+1, citations[i]));
        }
        return res;
    }
};