class Solution {
private:
    string RLE(string s){
        string s1;
        int i=1;
        while(i<=s.size()){
            
            int count=1;
            while (i<s.size() && s[i]==s[i-1]){
                count++;
                i++;
            
            }
            s1.push_back('0'+count);
            s1.push_back(s[i-1]);
            i++;
        }
        return s1;

    }
public:
    string countAndSay(int n) {
        string ans="1";
        for (int i=1; i<n; i++){
            ans=RLE(ans);
        }
        return ans;
    }
};