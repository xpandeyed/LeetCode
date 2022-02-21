class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(), n2 = nums2.size(), l1=0, l2=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        
        while(l1<n1 && l2<n2){
            if(nums1[l1]==nums2[l2]){
                res.push_back(nums1[l1]);
                l1++;
                l2++;
                continue;
            }
            while(l1<n1 && nums1[l1]<nums2[l2]){
                l1++;
            }
            
            while(l2<n2 && nums2[l2]<nums1[l1]){
                l2++;
            }
        }
        
        return res;
        
        
    }
};