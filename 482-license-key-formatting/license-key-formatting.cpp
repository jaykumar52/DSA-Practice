class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> arr;
        string ans;
        for (int i=0; i<s.size(); i++){
            if (s[i]!='-') arr.push_back(s[i]);
        }
        int i=arr.size()-1;
        int n=k;
        while(i>=0){
            while(i>=0 && n>0){
                ans.push_back(toupper(arr[i--]));
                n--;
            }
            ans.push_back('-');
            n=k;
        }
        if (arr.size()) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};