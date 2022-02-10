class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        int n=numCourses, i, count=0, curr;
        vector<int> indegrees(n, 0);
        vector<vector<int>> graph(n);
        for(auto x: prerequisites){
            graph[x[0]].push_back(x[1]);
            indegrees[x[1]]++;
        }

        queue<int> q;

        for(i=0; i<n; ++i){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto x : graph[curr]){
                indegrees[x]--;
                if(indegrees[x]==0){
                    q.push(x);
                }
            }
            count++;
        }
        
       if(count!=n){
           res.clear();
       }
        reverse(res.begin(), res.end());
        return res;
    }
};