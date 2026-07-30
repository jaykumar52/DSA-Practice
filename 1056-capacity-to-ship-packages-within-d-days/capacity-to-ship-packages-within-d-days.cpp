class Solution {
private:
    bool isPossible(vector<int> &weights, int &days, int mid){
        int totalDays=0;
        int i=0;
        while (i<weights.size()){
            int sum=0;
            while(i<weights.size() && sum<=mid){
                sum+=weights[i];
                if (sum<=mid) i++;
            }
            totalDays++;
        }
        if (totalDays<=days) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minD=0;
        int maxD=0;
        int ans;
        for (int i=0; i<weights.size(); i++){
            minD=max(minD, weights[i]);
            maxD+=weights[i];
        }
        while (minD<=maxD){
            int mid=minD+(maxD-minD)/2;
            if (isPossible(weights, days, mid)){
                ans=mid;
                maxD=mid-1;
            }
            else minD=mid+1;
        }
        return ans;
    }
};