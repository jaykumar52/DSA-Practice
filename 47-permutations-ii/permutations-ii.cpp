class Solution {
public:

    void helper(vector<int> &nums, vector<bool> &visited, vector<vector<int>> &ans, vector<int> &path){
        if (path.size()==nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i=0; i<nums.size(); i++){
            if (!visited[i]){
                if (i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
                path.push_back(nums[i]);
                visited[i]=true;
                helper(nums, visited, ans, path);
                path.pop_back();
                visited[i]=false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        vector<int> path;

        helper(nums, visited, ans, path);
        return ans;
    }
};