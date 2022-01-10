class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n1=nums1.size(), n2=nums2.size();
        vector<int> tempRes(n2, -1);
        for(int i=n2-1; i>=0; --i){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                tempRes[i]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> res(n1, -1);
        for(int i=0; i<n1; ++i){
            int index = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            res[i]=tempRes[index];
        }
        return res;
    }
};