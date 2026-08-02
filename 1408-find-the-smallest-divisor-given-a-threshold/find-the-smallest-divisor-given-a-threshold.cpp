class Solution {
private:
    bool isPossible(vector<int> &nums, int &threshold, int &mid){
        int sum=0;
        for (int num : nums){
            sum+=(num+mid-1)/mid;
        }
        if (sum<=threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minD=1;
        int maxD=*max_element(nums.begin(), nums.end());
        int ans=maxD;
        while(minD<=maxD){
            int mid=minD+(maxD-minD)/2;
            if (isPossible(nums, threshold, mid)){
                ans=mid;
                maxD=mid-1;
            }
            else minD=mid+1;
        }
        return ans;
    }
};