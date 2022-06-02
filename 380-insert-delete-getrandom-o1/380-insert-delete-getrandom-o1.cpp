class RandomizedSet {
public:
    
    unordered_set<int> s;
    
    
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool res = (s.find(val)==s.end());
        s.insert(val);
        return res;
    }
    
    bool remove(int val) {
        bool res = (s.find(val)!=s.end());
        s.erase(val);
        return res;
    }
    
    int getRandom() {
        auto it = next(s.begin(), rand()%s.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */