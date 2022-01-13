class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 1, startRange = points[0][0], endRange = points[0][1], n=points.size(), i=1;
        for(i=1; i<n; ++i){
            if(points[i][0]<=endRange){
                startRange=max(startRange, points[i][0]);
                endRange = min(endRange, points[i][1]);
                continue;
            }
            res++;
            startRange = points[i][0];
            endRange = points[i][1];
        }
        return res;
    }
};