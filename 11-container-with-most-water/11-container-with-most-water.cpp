class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(), start=0, end, res=0;
        end=n-1;
        while(start<end){
            res = max(res, min(height[start], height[end])*(end-start));
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        
        return res;
        
    }
};