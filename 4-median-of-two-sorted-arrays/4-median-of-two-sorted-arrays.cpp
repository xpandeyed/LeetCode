class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n1>n2){
            nums1.swap(nums2);
            swap(n1, n2);
        }
        
        if(n1==0){
            if(n2%2==0){
                return (double)(nums2[n2/2]+nums2[n2/2-1])/2;
            }else{
                return (double)(nums2[n2/2]);
            }
        }
        
        int l=0, h=n1, m1, m2, n1L, n1R, n2L, n2R;
        while(l<=h){
            m1=(l+h)/2;
            // cout << m1 << endl;
            n1L = m1!=0?nums1[m1-1]:INT_MIN;
            n1R = m1!=n1?nums1[m1]:INT_MAX;
            
            m2=((n1+n2+1)/2)-m1;
            // cout << m2 << endl;
            n2L = m2!=0?nums2[m2-1]:INT_MIN;
            n2R = m2!=n2?nums2[m2]:INT_MAX;
    
            if(n1L<=n2R && n2L<=n1R){
                if(n1%2==n2%2){
                    return (double)(max(n1L, n2L)+min(n1R, n2R))/2;
                }else{
                    return (double)(max(n1L, n2L));
                }
            }else if(n1L>n2R){
                h=m1-1;
            }else{
                l=m1+1;
            }
            
        }
        
        return 0;
    }
};