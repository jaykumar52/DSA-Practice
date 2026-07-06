class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> pre(nums.size()+1, 0);
        for (int i=1; i<=nums.size(); i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        if (pre[nums.size()]<target) return 0;
        int ans=nums.size();
        int i=0;
        int j=1;
        while(j<=nums.size()){
            if (pre[j]-pre[i] >= target){
                ans=min(ans, j-i);
                i++;
            }
            else j++;
        }
        return ans;
    }
};