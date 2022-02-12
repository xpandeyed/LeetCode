class Solution {
public:
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()){
            return 0;
        }
        
        unordered_set<string> words ;
        
        int l, i, j, n;
        string s, temp;
        n = wordList.size();
        for(i=0; i<n; ++i){
            words.insert(wordList[i]);
        }
        
        
        queue<pair<string, int>> q;
        
        q.push(pair<string, int>(beginWord, 1));
        
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            s = curr.first;
            l = curr.second;
            words.erase(s);
            if(s==endWord){
                return l;
            }
            n = s.size();
            for(i=0; i<n ; ++i){
                temp = s;
                for(j=0; j<26; ++j){
                    temp[i]=j+'a';
                    if(words.find(temp)!=words.end()){
                        q.push(pair<string, int>(temp, l+1));
                    }
                }
            }
        }
        return 0;
        
    }
};