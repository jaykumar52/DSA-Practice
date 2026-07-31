class Solution {
private:
    bool isPossible(int k, int m, vector<int> &bloomDay, int mid){
        int tempK=k;
        for (int day : bloomDay){
            if (day<=mid){
                tempK--;
                if (tempK==0){
                    m--;
                    tempK=k;
                }
            }
            else tempK=k;
        }
        if (m<=0) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long) m*k>bloomDay.size()) return -1;
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=0;
        while (start<=end){
            int mid=start+(end-start)/2;
            if (isPossible(k, m, bloomDay, mid)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};