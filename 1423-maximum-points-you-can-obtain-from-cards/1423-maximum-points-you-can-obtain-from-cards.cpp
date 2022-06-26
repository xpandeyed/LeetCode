class Solution {
public:
    int maxScore(vector<int>& cP, int k) {
        int n=cP.size(), i;
        int res = 0, curr;
        for(i=0;i<k;++i){
            res+=cP[i];
        }
        curr=res;
        for(i=n-1;i>=n-k;--i){
            curr+=cP[i];
            curr-=cP[i-n+k];
            res=max(res, curr);
        }
        return res;
    }
};