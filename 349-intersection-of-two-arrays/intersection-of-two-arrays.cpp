class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> first(nums1.begin(), nums1.end());
        unordered_set<int> second(nums2.begin(), nums2.end());
        vector<int> ans;
        for (auto it : first){
            if (second.count(it)) ans.push_back(it);
        }
        return ans;
    }
};