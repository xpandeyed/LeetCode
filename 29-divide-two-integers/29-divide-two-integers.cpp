class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int res = (long long int)dividend/(long long int)divisor;
        if(res>INT_MAX){
            return INT_MAX;
        }
        if(res<INT_MIN){
            return INT_MIN;
        }
        return res;
    }
};