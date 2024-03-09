class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1=x1-xCenter;
        x2=x2-xCenter;
        y1=y1-yCenter;
        y2=y2-yCenter;
        int x=x1*x2>0?min(pow(x1, 2), pow(x2, 2)):0;
        int y=y1*y2>0?min(pow(y1, 2), pow(y2, 2)):0;
        return x+y<=pow(radius, 2);
    }
};