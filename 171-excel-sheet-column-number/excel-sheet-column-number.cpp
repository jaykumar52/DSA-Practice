class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for (int i=columnTitle.size()-1; i>=0; i--){
            ans+=(columnTitle[i]-'A'+1)*pow(26, columnTitle.size()-i-1);
        }
        return ans;
    }
};