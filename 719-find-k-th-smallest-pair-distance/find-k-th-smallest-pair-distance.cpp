class Solution {
private:
    int countPair(vector<int> &nums, int mid){
        int count=0;
        int i=0;
        for (int j=1; j<nums.size(); j++){
            while (nums[j]-nums[i]>mid) i++;
            count+=(j-i);
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min=0;
        int max=nums[nums.size()-1]-nums[0];
        int ans=0;
        while (min<=max){
            int mid=min+(max-min)/2;
            if (countPair(nums, mid)>=k){
                max=mid-1;
                ans=mid;
            }
            else min=mid+1;
        }
        return ans;
    }
};