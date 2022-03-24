class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int n=heights.size(), i, res=0;
        for(i=0; i<n; ++i)
            if(heights[i]!=temp[i])res++;
        return res;
    }
};