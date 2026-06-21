class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num=0;
        for (int i=1; i<=nums.size(); i++){
            num=(num^i^nums[i-1]);
        }
        return num;
    }
};