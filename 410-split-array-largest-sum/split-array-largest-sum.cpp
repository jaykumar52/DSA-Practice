class Solution {
private:
    bool isPossible(vector<int> &nums, int &k, int mid){
        int currSum=0;
        int count=1;
        for (int num:nums){
            if (currSum+num>mid){
                count++;
                currSum=num;
            }
            else{
                currSum+=num;
            }
            if (count>k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (isPossible(nums, k, mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};