class Solution {
public:
    int minPartitions(string n) {
        int maxx=0;
        for(auto ch:n)
            maxx=max(maxx,ch-'0');
        return maxx;
    }
};