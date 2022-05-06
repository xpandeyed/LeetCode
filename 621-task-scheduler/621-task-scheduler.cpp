class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s=tasks.size(), count=0, i, ans=0;
        if(n==0){
            return s;
        }
        
        vector<int> freq(26, 0);
        for(i=0; i<s; ++i){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(), freq.end());
        int spaces = (freq[25]-1)*n;
        for(i=24; i>-1; --i){
            spaces-=min(freq[25]-1, freq[i]);
        }
        if(spaces>=0){
            return s+spaces;
        }
        return s;
    }
};