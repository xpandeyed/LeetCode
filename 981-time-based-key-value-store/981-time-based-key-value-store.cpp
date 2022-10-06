class TimeMap {
public:
   unordered_map<string,map<int,string>> structure;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        structure[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        
       map<int,string>::iterator it =structure[key].lower_bound(timestamp);
       if (it==structure[key].begin())
       {
           if(it->first>timestamp)
               return "";
           else
               return it->second;
       }
        else if (it==structure[key].end())
        {
            it--;
            if (structure[key].size()>0)
            {
                return (*it).second;
            }
        }
        else
        {
            if (it->first>timestamp)
                it--;
            
            return (*it).second;
        }
        return "";
        
    }
};