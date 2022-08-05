class Solution {
public:
    string reorganizeString(string s) {
        //count freq
        int i, n=s.size(), mfc=0, j;
        //mfc stores index of most frequent character

        vector<int> freq(26, 0);
        for(i=0;i<n;++i){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>freq[mfc]) mfc = s[i]-'a';
        }
        if(2*freq[mfc]-1>n) return "";// to be understood
        for(i=0;i<n and freq[mfc]>0;i+=2){
            freq[mfc]--;
            s[i]=('a'+mfc);
        }
        for(j=0;j<26;++j){
            while(freq[j]>0){
                if(i>=n) i=1;
                s[i]=('a'+j);
                freq[j]--;
                i+=2;
            }
        }
        return s;
        
    }
};