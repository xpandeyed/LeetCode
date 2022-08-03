class MyCalendar {
public:
    unordered_map<int, int> m;
    MyCalendar() {
        
    }
    
    bool book(int st, int en) {
        for(auto &[s, e]: m){
            if(!(e<=st || s>=en))
                return false;
        }
        m[st]=en;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */