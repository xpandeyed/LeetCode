class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> t(n+1, INT_MAX);
        t[k]=0;
        int i=0, s, d, time;
        for(i=0; i<n; ++i){
            for(auto x: times){
                s=x[0], d=x[1], time = x[2];
                if(t[s]!=INT_MAX and t[d]>t[s]+time){
                    t[d]=t[s]+time;
                }
            }
        }
        int res=0;
        for(i=1; i<=n; ++i)
            res=max(res, t[i]);
        return res==INT_MAX?-1:res;
        
    }
};