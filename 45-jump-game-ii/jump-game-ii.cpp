class Solution {
public:
    int jump(vector<int>& nums) {
        int start = nums.size()-1;
        int Jump = 0;

        while (start!=0) {
            int temp=0;
            for (int i=start-1; i>=0; i--){
                if (nums[i]>=start-i) temp=i;
            }
            start=temp;
            Jump++;

        }
        return Jump;
    }
};