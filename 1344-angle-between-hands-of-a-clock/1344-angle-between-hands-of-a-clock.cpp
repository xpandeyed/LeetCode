class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=0.5*(double)minutes + 30.0*hour, m = 6.0*minutes;
        // cout << h  << " " << m << endl;
        return min(360-abs(h-m), abs(h-m));
    }
};