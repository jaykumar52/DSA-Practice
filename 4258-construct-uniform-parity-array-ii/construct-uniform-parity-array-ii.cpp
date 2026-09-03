class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd=INT_MAX;
        for (int num : nums1) if (num&1) minOdd=min(minOdd, num);
        if (minOdd==INT_MAX) return true;
        bool ans=true;
        for (int num : nums1){
            if (num%2==0 && num-minOdd<1) ans=false;
        }
        return ans;
    }
};