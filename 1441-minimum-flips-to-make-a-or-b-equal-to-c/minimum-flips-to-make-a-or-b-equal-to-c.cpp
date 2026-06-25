class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for (int i=0; i<32; i++){
            int bitA=(a>>i)&1;
            int bitB=(b>>i)&1;

            if ((c>>i)&1){
                if ((bitA|bitB)==0) ans++;
            }
            else{
                if (bitA&bitB) ans+=2;
                else if (bitA|bitB) ans++;
            }
        }
        return ans;
    }
};