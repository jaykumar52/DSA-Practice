class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for (int i=0; i<nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        for(auto it : map){
            if (it.second.size()>1){
                for (int i=0; i<it.second.size(); i++){
                    for (int j=i+1; j<it.second.size(); j++){
                        if (abs(it.second[i]-it.second[j])<=k) return true;
                    }
                }
            }
        }
        return false;
        
    }
};