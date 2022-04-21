class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        long long int res = INT_MAX, l=1, h=INT_MAX, m, i, n=piles.size(), time;
        while(l<=h){
            m=l+(h-l)/2;
            i=0;
            time=0;
            while(i<n){
                time+=(piles[i]/m);
                if(piles[i]%m){
                    time++;
                }
                i++;
            }
            if(time>hours){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return l;
        
    }
};