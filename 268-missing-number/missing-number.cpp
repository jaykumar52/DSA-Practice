class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num=0;
        for (int i=1; i<=nums.size(); i++){
            num=(num^i);
        }
        for (int j=0; j<nums.size(); j++){
            num=(num^nums[j]);
        }
        return num;
    }
};