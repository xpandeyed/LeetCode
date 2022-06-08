class Solution {
public:
    int numDecodings(string s) {
        int n=s.size(), i;
        vector<int> dp(n, 0);
        if(s[n-1]!='0') dp[n-1]=1;
        if(n-2>-1 and s[n-2]!='0'){
            string curr="";
            curr+=s[n-2];
            curr+=s[n-1];
            if(curr<="26"){
                dp[n-2]=1+dp[n-1];
            }else{
                dp[n-2]=dp[n-1];
            }
        }
        for(i=n-3;i>-1;--i){
            if(s[i]=='0') continue;
            string curr="";
            curr+=s[i];
            curr+=s[i+1];
            if(curr<="26"){
                dp[i]=dp[i+1]+dp[i+2];
            }else{
                dp[i]=dp[i+1];
            }
        }
        return dp[0];
    }
};