class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        int j=1;
        unordered_set<int> set;
        set.insert(nums[i]);
        while(j<nums.size()){
            if (j-i <= k){
                if (set.count(nums[j])) return true;
                set.insert(nums[j]);
                j++;
            }
            else{
                set.erase(nums[i]);
                i++;
                if (set.count(nums[j])) return true;
                set.insert(nums[j]);
                j++;
            }
        }
        return false;

    }
};