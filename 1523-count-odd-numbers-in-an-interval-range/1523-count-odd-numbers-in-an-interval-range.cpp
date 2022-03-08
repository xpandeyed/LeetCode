class Solution {
public:
    int countOdds(int low, int high) {
        long long int res = (((long long int)high) - ((long long int)low))/2;
        
        if(low%2==0 and high%2==0){
            return res;
        }
        
        return res+1;
    }
};