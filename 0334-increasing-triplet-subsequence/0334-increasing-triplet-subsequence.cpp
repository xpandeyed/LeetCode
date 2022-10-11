class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lic;
        for(int n: nums){
            auto it = lower_bound(lic.begin(), lic.end(), n);
            if(it==lic.end()){
                lic.push_back(n);
            }else{
                *it = n;
            }
            if(lic.size()>=3){
                return true;
            }
        }
        if(lic.size()>=3){
            return true;
        }
        return false;
    }
};