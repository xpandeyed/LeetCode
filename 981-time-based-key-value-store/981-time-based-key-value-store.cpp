class TimeMap {
public:
    
    unordered_map<string, map<int , string>> m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].lower_bound(timestamp);
        if(it==m[key].end()){
            if(m[key].size()!=0){
                it--;
                return (*it).second;
            }else{
                return "";
            }
        }
        if((*it).first==timestamp){
            return (*it).second;
        }
        if((*it).first>timestamp and it!=m[key].begin()){
            it--;
            return (*it).second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */