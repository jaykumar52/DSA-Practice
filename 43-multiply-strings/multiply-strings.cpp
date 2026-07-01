class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        vector<int> ans(num1.size()+num2.size(), 0);
        for (int i=num1.size()-1; i>=0; i--){
            for (int j=num2.size()-1; j>=0; j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                mul+=ans[i+j+1];
                ans[i+j+1]=mul%10;
                ans[i+j]+=mul/10;
            }
        }
        string s="";
        for (int num : ans){
            if (s.empty() && num==0) continue;
            else s.push_back('0'+num);
        }
        return s;
    }
};