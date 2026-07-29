class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long square = (long long) mid*mid;
            if (square>num) end=mid-1;
            else if (square<num) start=mid+1;
            else return true;
        }
        return false;
    }
};