class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int num=nums[0];
        int i=0;
        while (i<nums.size()){
            if (num==nums[i]){
                num++;
                i++;
            }
            else {
                ans.push_back(num);
                num++;
            }
        }
        return ans;
    }
};