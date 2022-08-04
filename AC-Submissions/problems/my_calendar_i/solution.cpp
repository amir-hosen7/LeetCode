class MyCalendar {
public:
    
    MyCalendar() {
        
    }
    
    map<int,int> bookings;
    bool book(int start, int end) {
        auto it=bookings.upper_bound(start);
        if(it==bookings.end() or (it->second)>=end){
            bookings[end]=start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */