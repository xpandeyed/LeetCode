class Solution {
public:
    map<pair<int, int>, long long int> m;
    int mod = 1000000000+7;
    long long int help(int n, int k, int t){
        if(m.find(make_pair(n, t))!=m.end()) return m[make_pair(n, t)];
        if(n==1){
            if(t<0 or t>k) return m[make_pair(n, t)] = 0;
            return m[make_pair(n, t)] = 1;
        }
        long long int res = 0;
        for(int i=1;t-i>=n-1 and i<=k;++i){
            res+=help(n-1, k, t-i);
            res%=mod;
        }
        return m[make_pair(n, t)] = res;
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        return help(n, k, target)%mod;
    }
};