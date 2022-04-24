class UndergroundSystem {
public:
    map<int, pair<pair<string, int>, pair<string, int>>> m;
    
    map<pair<string ,string>, vector<int>> durations;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<string, int> start = {stationName, t}, end={"", 0};
        m[id]=make_pair(start, end);
    }
    
    void checkOut(int id, string stationName, int t) {
        m[id].second = make_pair(stationName, t);
        pair<string, string> p = make_pair(m[id].first.first, m[id].second.first);
        durations[p].push_back(t-m[id].first.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double time=0.0;
        int i=0;
        auto p = make_pair(startStation, endStation);
        for(auto t: durations[p]){
            time+=t;
            i++;
        }
        time/=i;
        return time;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */