class Solution {
public:
    vector<string> turn(string curr, int i){
        vector<string> res(2, curr);
        res[0][i] = (((res[0][i]-'0'+1)%10)+'0');
        res[1][i] = (((res[1][i]-'0'+9)%10)+'0');
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        
        
        set<string> visited ;
        
        queue<string> bfs;
        
        int res = 0, i, j, n;
        
        string curr = "0000", temp;
        if(curr==target){
            return 0;
        }
        
        for(string x: deadends){
            visited.insert(x);
            if(x==curr) return -1;
        }
        
        bfs.push(curr);
        visited.insert(curr);
        
        while(!bfs.empty()){
            res++;
            n=bfs.size();
            // cout << n << endl;
            for(i=0; i<n; ++i){
                string t = bfs.front();
                bfs.pop();
                for(j=0; j<4; ++j){
                    // cout << "h" << endl;
                    for(auto y: turn(t, j)){
                        // cout << "i" << endl;
                        if(visited.find(y)==visited.end()){
                            if(y==target){
                                return res;
                            }
                            visited.insert(y);
                            bfs.push(y);
                        }
                    }
                }
            }
            
            
        }
        
        return -1;
        
        
    }
};