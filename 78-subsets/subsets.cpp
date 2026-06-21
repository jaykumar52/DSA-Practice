class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1<<nums.size());
        for (int i=0; i<(1<<nums.size()); i++){
            int pos=0;
            int j=i;
            while(j>0){
                if (j&1) ans[i].push_back(nums[pos]);
                pos++;
                j=j>>1;
            }
        }
        return ans;
        
    }
};