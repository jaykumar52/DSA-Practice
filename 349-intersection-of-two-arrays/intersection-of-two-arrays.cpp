class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> first(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num : nums2){
            if (first.count(num)) {
                ans.push_back(num);
                first.erase(num);
            }
        }
        return ans;
    }
};