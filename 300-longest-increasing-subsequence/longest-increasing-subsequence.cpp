class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int num : nums){
            auto it = lower_bound(seq.begin(), seq.end(), num);
            if ( it == seq.end()) seq.push_back(num);
            else *it=num;
        }
        return seq.size();
    }
};