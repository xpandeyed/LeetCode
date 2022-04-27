class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        long long int l=1, h=INT_MAX, m, res=INT_MAX, curr;
        while(l<=h){
            m=(l+h)/2;
            curr=0;
            for(int x: nums){
                curr+=(ceil((double)x/m));
            }
            if(curr<=t){
                res=min(res, m);
                h=m-1;
            }else{
                l=m+1;
            }
            
        }
        return res;
    }
};