class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(), false));
        vector<int> ans(2,0);
        for (int i=0; i<s.size(); i++){
            dp[i][i]=true;
            if (i<s.size()-1 && s[i]==s[i+1]){
                dp[i][i+1]=true;
                ans={i,i+1};
            } 
        }
        if (s.size()<=2){
            return s.substr(ans[0], ans[1]-ans[0]+1);
        }
        for (int i=3; i<=s.size(); i++){
            for (int j=0; j<=s.size()-i; j++){
                dp[j][j+i-1]=(s[j]==s[j+i-1]) & dp[j+1][j+i-2];
                if (dp[j][j+i-1]) ans={j,j+i-1};
            }
        }

        return s.substr(ans[0], ans[1]-ans[0]+1);
    }
};