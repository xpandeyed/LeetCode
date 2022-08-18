class Solution {
public:
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        if(x==0) return 0;
        unordered_set<int> s(forb.begin(), forb.end()), fo, ba;
        int ans = 0, last = 10000;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while(!q.empty()){
            
            int n = q.size();
            ans++;
            
            while(n--){
                
                auto curr = q.front();
                q.pop();
                
                 
                int node = curr.first;
                int back = curr.second;
                
                // cout << "From: " << node << " Back: " << back << endl;
                
                if(node+a==x) return ans;
                
                if(node+a<last and s.find(node+a)==s.end() and fo.find(node+a)==fo.end()){
                    fo.insert(node+a);
                    // cout << "To: " << node+a << endl;
                    q.push(make_pair(node+a, 1));
                }
                
                
                if(s.find(node-b)==s.end() and node-b==x and back>0) return ans;
                if(node-b>0 and s.find(node-b)==s.end() and back>0 and ba.find(node-b)==ba.end()){
                    ba.insert(node-b);
                    // cout << "To: " << node-b << endl;
                    q.push(make_pair(node-b, back-1));
                }
                
            }
            
        }
        return -1;
    }
};