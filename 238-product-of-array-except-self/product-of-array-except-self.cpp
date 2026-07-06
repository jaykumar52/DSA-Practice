class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        // 1, 1, 2, 6,24,1  -1,-1, 0, 0, 0
        // 1,24,24,12,4 ,1   0, 0, 0,-9, 3
        vector<int> preProduct(nums.size(),1);
        vector<int> postProduct(nums.size(),1);
        for (int i=1; i<preProduct.size(); i++){
            preProduct[i]=preProduct[i-1]*nums[i-1];
            postProduct[nums.size()-i-1]=postProduct[nums.size()-i]*nums[nums.size()-i];
        }
        for (int i=0; i<nums.size(); i++){
            ans[i]=preProduct[i]*postProduct[i];
        }
        return ans;
    }
};