class Solution {
public:
    int kthFactor(int n, int k) {
        int i;
        for(i=1;i<=n;++i){
            if(n%i==0 and --k==0){
                return i;
            }
        }
        return -1;
    }
};