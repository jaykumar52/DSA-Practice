class Solution {
public:
    int hammingWeight(int n) {
        int setBit=0;

        while (n!=0){
            if (n&1) setBit++;
            n=n>>1;
        }
        return setBit;
    }
};