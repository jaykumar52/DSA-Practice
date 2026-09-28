class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int par=0;
        for (char c : s){
            if (c=='(') par++;
            else if (c==')') par--;
            ans=max(ans, par);
        }
        return ans;
    }
};