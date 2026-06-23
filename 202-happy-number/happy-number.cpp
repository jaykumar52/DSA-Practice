class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set = {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100};
        while(n>100){
            int newN=0;
            while(n>0){
                newN+=(n%10)*(n%10);
                n=n/10;
            }
            n=newN;
        }
        return set.count(n);
    }
};