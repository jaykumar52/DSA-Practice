class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool negative = (dividend<0) ^ (divisor<0);

        long long absdividend = abs((long long)dividend);
        long long absdivisor = abs((long long)divisor);
        long long quotient=0;

        while (absdivisor<=absdividend){
            long long tempDivisor = absdivisor;
            long long multiple=1;

            while((tempDivisor<<1)<=absdividend){
                tempDivisor=tempDivisor<<1;
                multiple=multiple<<1;
            }
            quotient+=multiple;
            absdividend-=tempDivisor;
        }
        

        if (negative) return -(quotient);
        else return quotient;
            
        
    }
};