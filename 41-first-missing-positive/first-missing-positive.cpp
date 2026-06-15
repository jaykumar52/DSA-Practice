class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> set;
        for (int i=0; i<n; i++){
            set.insert(nums[i]);
        }

        for (int i=1; i<=n+1; i++){
            if (set.count(i)==0) return i;
        }
        return 0;
    }
};