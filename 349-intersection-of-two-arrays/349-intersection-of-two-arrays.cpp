class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), i;
        vector<int> res;
        for(i=0; i<n; ++i){
            if(find(nums2.begin(), nums2.end(), nums1[i])!=nums2.end() && find(res.begin(), res.end(), nums1[i])==res.end()){
                res.push_back(nums1[i]);
            }
        }
        return res;
    }
};