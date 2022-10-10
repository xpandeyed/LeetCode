class Solution {
public:
    int reverse(int x) {
        long long int res=0;
        while(x){
            res*=10;
            if(res>INT_MAX or res<INT_MIN) return 0;
            res+=(x%10);
            x/=10;
        }
        return res;
    }
};