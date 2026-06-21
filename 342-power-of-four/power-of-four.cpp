class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n>0 && (n&(n-1))==0){
            int count=-1;
            while (n>0){
                count++;
                n=n>>1;
            }
            if ((count&1)==0) return true;
        }
        return false;
    }
};