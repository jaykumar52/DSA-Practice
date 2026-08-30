class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minnum=0;
        int maxnum=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]>nums[maxnum]) maxnum=i;
            if (nums[i]<nums[minnum]) minnum=i;
        }
        int left = min(minnum, maxnum);
        int right = max(minnum, maxnum);
        int n=nums.size();
        return min(min(right+1, n-left), left+1+n-right);
    }
};