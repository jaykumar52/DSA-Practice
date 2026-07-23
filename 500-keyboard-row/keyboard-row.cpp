class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        
        for (string s : words){
            bool flag1=true;
            bool flag2=true;
            bool flag3=true;
            string row1="QWERTYUIOPqwertyuiop";
            string row2="ASDFGHJKLasdfghjkl";
            string row3="ZXCVBNMzxcvbnm";
            for (char c : s){
                if (!row1.contains(c)){
                    flag1=false;
                }
            }
            for (char c : s){
                if (!row2.contains(c)){
                    flag2=false;
                }
            }
            for (char c : s){
                if (!row3.contains(c)){
                    flag3=false;
                }
            }
            if (flag1 || flag2 || flag3) ans.push_back(s);
        }
        return ans;
    }
};