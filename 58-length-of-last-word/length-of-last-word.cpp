class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        int j;
        for (j=s.size()-1; j>=0; j--){
            if (s[j]!=' ') break;
        }
        for (int i=j; i>=0; i--){
            if (s[i]!=' ') length++;
            else return length;
        }
        return length;
    }
};