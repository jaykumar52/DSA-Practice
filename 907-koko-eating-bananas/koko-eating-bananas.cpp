class Solution {
private:
    bool canEat(int mid, int &h, vector<int>& piles){
        long long hours=0;
        for (int i=0; i<piles.size(); i++){
            hours+=(piles[i]+mid-1)/mid;
        }
        if (hours<=h) return true;
        else return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minH=1;
        int maxH=0;
        int ans;
        for (int i=0; i<piles.size(); i++){
            maxH=max(maxH, piles[i]);
        }
        while (minH<=maxH){
            int mid=minH+(maxH-minH)/2;
            if (canEat(mid, h, piles)){
                ans=mid;
                maxH=mid-1;
            }
            else minH=mid+1;
        }
        return ans;
    }
};