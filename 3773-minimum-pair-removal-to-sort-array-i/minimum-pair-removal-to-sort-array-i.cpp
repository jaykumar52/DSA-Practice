class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations=0;
        while (nums.size()>1){
            bool isSorted=true;
            int minIndex=-1;
            int minSum=INT_MAX;

            for (int i=0; i<nums.size()-1; i++){
                if (nums[i]>nums[i+1]) isSorted=false;
                if (nums[i]+nums[i+1]<minSum){
                    minSum=nums[i]+nums[i+1];
                    minIndex=i;
                }
            }
            if (isSorted) break;
            nums[minIndex]=minSum;
            nums.erase(nums.begin()+minIndex+1);
            operations++;
        }
        return operations;
    }
};