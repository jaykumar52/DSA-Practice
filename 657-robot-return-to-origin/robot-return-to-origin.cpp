class Solution {
public:
    bool judgeCircle(string moves) {
        int hCount=0;
        int vCount=0;
        for (char move : moves){
            if (move=='R') hCount++;
            else if (move=='L') hCount--;
            else if (move=='U') vCount++;
            else vCount--;
        }
        return vCount==0 && hCount==0;
    }
};