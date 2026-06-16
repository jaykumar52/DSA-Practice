class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int i=0; i<nums.size(); i++){
            strNums.push_back(to_string(nums[i]));
        }

        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            return a+b > b+a;
        });

        if (strNums[0]=="0") return "0";
        string ans;
        for (int i=0; i<strNums.size(); i++) ans+=strNums[i];

        return ans;
    }
};