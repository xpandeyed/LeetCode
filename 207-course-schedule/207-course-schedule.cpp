class Solution {
public:
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegrees(numCourses, 0);
        
        vector<vector<int>> graph(numCourses);
        int n=prerequisites.size(), i;
        for(i=0; i<n; ++i){
            indegrees[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        queue<int> q;
        for(i=0; i<numCourses; ++i){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        
        int count = 0 , curr;
        
        while(!q.empty()){
            curr = q.front();
            q.pop();
            count++;
            for(auto nei: graph[curr]){
                indegrees[nei]--;
                if(indegrees[nei]==0){
                    q.push(nei);
                }
            }
        }
        
        //cout << count << " " << numCourses << endl;
        
        return count==(numCourses);
        
    }
};