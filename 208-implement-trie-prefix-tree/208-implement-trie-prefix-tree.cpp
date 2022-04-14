class TrieNode{
    public:
    bool isEnd = false;
    vector<TrieNode*> nexts;
    int c;
};


class Trie {
public:
    vector<TrieNode*> initials;
    Trie() {
        initials = vector<TrieNode*>(26, NULL);
    }
    
    void insert(string word) {
        vector<TrieNode*> *temp = &initials;
        int i=0, n=word.size();
        while(i<n){
            if((*temp)[word[i]-'a']==NULL){
                (*temp)[word[i]-'a']=new TrieNode;
                (*temp)[word[i]-'a']->nexts = vector<TrieNode*>(26, NULL);
            }
            if(i==n-1){
                (*temp)[word[i]-'a']->isEnd = true;
            }
            temp = &(*temp)[word[i]-'a']->nexts;
            i++;
        }
    }
    
    bool search(string word) {
        vector<TrieNode*> *temp = &initials;
        int i=0, n=word.size();
        while(i<n){
            // cout << i << endl;
            // cout << (*temp)[word[i]-'a']->isEnd << endl;
            if((*temp)[word[i]-'a']==NULL){
                // cout << ((*temp)[word[i]-'a']+'a') << endl;
                return false;
            }else if(i==n-1 and (*temp)[word[i]-'a']->isEnd==false){
                return false;
            }
            temp = &(*temp)[word[i]-'a']->nexts;
            i++;
        }
        return true;
    }
    
    bool startsWith(string word) {
        vector<TrieNode*> *temp = &initials;
        int i=0, n=word.size();
        while(i<n){
            if((*temp)[word[i]-'a']==NULL){
                return false;
            }
            temp = &(*temp)[word[i]-'a']->nexts;
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */