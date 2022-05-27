class Solution {
public:
    int numberOfSteps(int num) {
        int res=0;
        while(num){
            res++;
            if(num%2){
                num--;
            }else{
                num/=2;
            }
            // cout << num << endl;
        }
        return res;
    }
};