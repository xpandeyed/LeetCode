class Solution {
public:
    int getSum(int a, int b) {
        bool flag = b<0?true:false;
        b = abs(b);
        for(int i=0;i<b;++i){
            if(flag)a--;
            else a++;
        }
        return a;
    }
};