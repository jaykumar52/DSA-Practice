class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minnum=0;
        int maxnum=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]>nums[maxnum]){
                maxnum=i;
            }
            if (nums[i]<nums[minnum]){
                minnum=i;
            }
        }
        return min(min(max(minnum, maxnum)+1, (int)nums.size()-min(minnum, maxnum)), min(minnum, maxnum)+1+(int)nums.size()-max(minnum, maxnum));
    }
};