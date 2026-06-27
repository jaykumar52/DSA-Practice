class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int ans=0;
        while(!s.empty()){
            int count=0;
            int startNum=*(s.begin());
            while(s.count(startNum-1)) startNum-=1;
            while(s.count(startNum)){
                s.erase(startNum);
                count++;
                startNum++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};