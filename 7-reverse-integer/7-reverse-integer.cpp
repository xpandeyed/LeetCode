class Solution {
public:
    int reverse(int x) {
        long long int num = (long long int) x;
        
        bool isNegative = false;
        if(num<0){
            isNegative = true;
            num*=-1;
        }
        long long res = 0;
        while(num>0){
            res*=10;
            res+=(num%10);
            num/=10;
        }
        
        if(isNegative){
            res*=-1;
        }
        
        if(res<-2147483648)
        {
            return 0;
        }
        
        if(res>2147483647){
            return 0;
        }
        
        
        return res;
    }
};