class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int> a, vector<int> b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        priority_queue<int> durations;
        int res=0, n=courses.size(), i, day=0, curr;
        for(i=0;i<n;++i){
            curr = res;
            while(day+courses[i][0]>courses[i][1] and (!durations.empty() and durations.top()>courses[i][0])){
                day-=durations.top();
                durations.pop();
                curr--;
            }
            if(day+courses[i][0]<=courses[i][1]){
                curr++;
                day+=courses[i][0];
                durations.push(courses[i][0]);
            }
            res=max(curr, res);
        }
        return res;
    }
};
