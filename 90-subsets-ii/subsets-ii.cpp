class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &path, int index, vector<int> &nums, set <vector<int>> &st){
        if (index==nums.size()){
            if (st.count(path)==0) {
                ans.push_back(path);
                st.insert(path);
            }
            return;
        }
        helper(ans, path, index+1, nums, st);
        path.push_back(nums[index]);
        helper(ans, path, index+1, nums, st);
        path.pop_back();
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        set<vector<int>> st;
        helper(ans, path, 0, nums, st);
        return ans;
    }
};