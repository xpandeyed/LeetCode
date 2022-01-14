class Solution {
public:
    int myAtoi(string s) {
        int n=s.size(), i=0, tens=1;
        long long int res = 0;
        int modi = -2;
        bool integerEnc = false;
        for(int i=0; i<n; ++i){
            
            if(s[i]=='.'){
                break;
            }
            
            if(s[i]>=65 && s[i]<=90){
                break;
            }
            
            if(s[i]>=97 && s[i]<=122){
                break;
            }
            
            if(res>=2147483648 && modi==-1){
                return -2147483648;
            }
            if(res>=2147483647){
                return 2147483647;
            }
            if(s[i]>=65 && ((s[i]!='+' && s[i]!='-') && s[i]!=' ') ){
                break;
            }
            
            if(s[i]>=48 && s[i]<=57){
                integerEnc=true;
                res*=10;
                res+=(s[i]-48);
                continue;
            }
            if((s[i]<48 || s[i]>57) && (integerEnc || modi!=-2)){
                break;
            }
            if(s[i]=='-'){
                modi=-1;
            }
            if(s[i]=='+'){
                modi=1;
            }
            
        }
        if(res>=2147483648 && modi==-1){
                return -2147483648;
        }

        if(modi!=-2){
            res*=modi;
        }
        if(res>=2147483647){
                return 2147483647;
        }
        return res;
    }
};