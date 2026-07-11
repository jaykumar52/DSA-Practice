class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int ans=-1;
        for (char c : s) map[c]++;
        for (int i=0; i<s.size(); i++){
            if (map[s[i]]==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};