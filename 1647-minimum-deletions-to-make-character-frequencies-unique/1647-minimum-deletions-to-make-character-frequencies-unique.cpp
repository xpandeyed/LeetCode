class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto c: s){
            freq[c-'a']++;
        }
        int res = 0, i;
        sort(freq.begin(), freq.end());
        // cout << freq[25] << " ";
        for(i=24; i>-1;--i){
            // cout << freq[i] << " ";
            if(freq[i]==0){
                break;
            }
            int j=i;
            while(j<25 and freq[j]>=freq[j+1]){
                if(freq[j]==1){
                    res++;
                    freq[j]=0;
                    break;
                }else{
                    if(freq[j+1]==0){
                        res+=abs(freq[j]-freq[j+1]);
                        freq[j]=0;
                    }else{ 
                        res+=(abs(freq[j]-freq[j+1])+1);
                        freq[j]-=(abs(freq[j]-freq[j+1])+1);
                    }
                }
                j++;
            }
            
        }
        return res;
    }
};