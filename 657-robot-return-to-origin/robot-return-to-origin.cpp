class Solution {
public:
    bool judgeCircle(string moves) {
        int hCount=0;
        int vCount=0;
        for (int i=0; i<moves.size(); i++){
            if (moves[i]=='R') hCount++;
            else if (moves[i]=='L') hCount--;
            else if (moves[i]=='U') vCount++;
            else vCount--;
        }
        return vCount==0 && hCount==0;
    }
};