class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xOr = 0;
        for (int i=0; i<nums.size(); i++){
            xOr=xOr^nums[i];
        }

        long long rightmostBit=xOr & -xOr;

        int num1=0;
        int num2=0;

        for (int i=0; i<nums.size(); i++){
            if (nums[i] & rightmostBit) num1^=nums[i];
            else num2^=nums[i];
        }

        return {num1,num2};
    }
};