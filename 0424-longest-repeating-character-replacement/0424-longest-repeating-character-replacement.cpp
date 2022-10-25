class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), i=0, st=0, tbr=0, res=1, mf=0, mfc=0, pi;
        set<int> done;
        //st is start of window
        //tbr is number of characters to be replaced
        //mf is max freq of among the characters
        //m stores freq of characters in current window
        map<int, int> m;
        if(n==k) return n;
        while(i<n){
            m[s[i]]++;
            mf = 0;
            mfc = 0;
            for(auto [c, f]: m){
                if(mf<f){
                    mf=f;
                    mfc=c;
                }
            }
            // cout << "curr char: " << s[i] << " mfc: " << (char)mfc; 
            tbr = (i-st+1)-mf;
            if(tbr<=k) res = max(res, i-st+1);
            //keep increasing start until i find tbr>k and a non matching char is not found
            // cout << " window: " << st << " : " << i << " tbr: " << tbr << endl;
            while(st<i and tbr>k){
                tbr--;
                m[s[st]]--;
                st++;
            }
            i++;
        }
        return res;
        
    }
};
//window size = number of same character + k