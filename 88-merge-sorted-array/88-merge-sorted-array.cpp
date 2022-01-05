class Solution {
public:
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if(n==0){
        return ;
    }
    if(m==0){
    for (int i = m; i < m + n; ++i)
    {
        nums1[i] = nums2[i - m];
    }
        return ;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        int j = m - 2;
        int last = nums1[j + 1];
        while (j >= 0 && nums1[j] > nums2[i])
        {
            nums1[j + 1] = nums1[j];
            j--;
        }
        if(nums1[j+1]<nums2[i]){
            continue;
        }

        nums1[j + 1] = nums2[i];
        nums2[i] = last;
        // cout << "nums1: " ;
        // for(auto x : nums1){
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "nums2: " ;
        // for(auto x : nums2){
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    for (int i = m; i < m + n; ++i)
    {
        nums1[i] = nums2[i - m];
    }

    // cout << "Final Result : " ;
    // for(auto x: nums1) {
    //     cout << x << " " ;
    // }
}
};