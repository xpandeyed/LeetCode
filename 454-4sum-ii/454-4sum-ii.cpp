class Solution {
public:
    
    map<int, int> countFrequency(vector<int> arr1, vector<int> arr2){
        map<int, int> res;
        
        for(auto x: arr1){
            for(auto y: arr2){
                if(res.find(x+y)==res.end()){
                    res[x+y]=1;
                }else{
                    res[x+y]++;
                }
            }
        }
        
        
        return res;
    }
    
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> m1, m2;
        
        m1 = countFrequency(nums1, nums2);
        m2 = countFrequency(nums3, nums4);
        
        int res = 0;
        
        for(auto x: m1){
            if(m2.find(-(x.first))!=m2.end()){
                    res+=(x.second*m2[-(x.first)]);
            }
        }
        
        return res;
        
    }
};