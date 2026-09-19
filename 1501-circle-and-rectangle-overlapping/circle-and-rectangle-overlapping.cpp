class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (xCenter<=x2 && xCenter>=x1 && yCenter<=y2 && yCenter>=y1) return true;

        if (yCenter>y2 && yCenter<=y2+radius && xCenter<=x2 && xCenter>=x1) return true;

        if (yCenter<y1 && yCenter>=y1-radius && xCenter<=x2 && xCenter>=x1) return true;

        if (xCenter>x2 && xCenter<=x2+radius && yCenter<=y2 && yCenter>=y1) return true;

        if (xCenter<x1 && xCenter>=x1-radius && yCenter<=y2 && yCenter>=y1) return true;

        if ((long long)pow(xCenter-x1,2)+(long long)pow(yCenter-y2,2)<=(long long)pow(radius, 2)) return true;

        if ((long long)pow(xCenter-x2,2)+(long long)pow(yCenter-y2,2)<=(long long)pow(radius, 2)) return true;

        if ((long long)pow(xCenter-x1,2)+(long long)pow(yCenter-y1,2)<=(long long)pow(radius, 2)) return true;

        if ((long long)pow(xCenter-x2,2)+(long long)pow(yCenter-y1,2)<=(long long)pow(radius, 2)) return true;

        return false;
    }
};