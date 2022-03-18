class Solution {
public:   
    string removeDuplicateLetters(string s) {
        vector<int> lastOccurrence(26, -1);
        vector<bool> visited(26, false);
        
        int i, n=s.size();
        
        stack<int> chars, temp;
        
        for(i=0; i<n; ++i){
            lastOccurrence[s[i]-'a']=i;
        }
        
        for(i=0; i<n; ++i){
            if(visited[s[i]-'a']){
                continue;
            }
            
            
            if(chars.empty() or chars.top()<s[i]){
                chars.push(s[i]);
                visited[s[i]-'a']=true;
                continue;
            }
            
            while(!chars.empty() and (chars.top()>s[i] and lastOccurrence[chars.top()-'a']>i)){
                visited[chars.top()-'a']=false;
                chars.pop();
            }
            
            visited[s[i]-'a']=true;
            chars.push(s[i]);
            
            
            // while(!temp.empty()){
            //     temp.pop();
            // }
            // while(!chars.empty()){
            //     cout << (char)chars.top() << " ";
            //     temp.push(chars.top());
            //     chars.pop();
            // }
            
            // while(!temp.empty()){
            //     chars.push(temp.top());
            //     temp.pop();
            // }
            // cout << endl;
        }
        
        string res = "";
        
        while(!chars.empty()){
            res+=chars.top();
            chars.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};