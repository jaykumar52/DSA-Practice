class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int jump = 0;
        int currEnd = 0;

        for (int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, i+nums[i]);
            if (i==currEnd){
                jump++;
                currEnd=farthest;
                if (currEnd>nums.size()-1) break;
            }


        }
        return jump;
    }
};