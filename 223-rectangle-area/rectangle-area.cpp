class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=abs((ax2-ax1)*(ay2-ay1)) + abs((by2-by1)*(bx2-bx1));
        if (min(ay2, by2)>max(ay1, by1) && min(ax2, bx2)>max(ax1, bx1)){
            area-=(min(ax2, bx2)-max(ax1, bx1))*(min(ay2, by2)-max(ay1, by1));
        }
        return area;
    }
};