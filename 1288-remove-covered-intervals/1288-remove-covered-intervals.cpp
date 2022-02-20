    bool compare(vector<int> &v1, vector<int> &v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
class Solution {
public:

    
    int bruteForce(vector<vector<int>>& intervals){
        int n=intervals.size(), i, res=0, j, flag;
        sort(intervals.begin(), intervals.end(), compare);
        
        for(i=0; i<n; ++i){
            j=i-1;
            flag=0;
            while(j>=0){
                if(intervals[j][1]>=intervals[i][1]){
                    flag = 1;
                    break;
                }
                j--;
            }
            if(flag==0){
                res++;
            }
        }
        
        return res;
        
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        return bruteForce(intervals);
    }
};