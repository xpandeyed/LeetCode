class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int x = n;
        return x && (!(x&(x-1)));
    }
};