class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int index=-1;
        while (i<haystack.size()){
            if (haystack[i]==needle[j]){
                j++;
                i++;
            }
            else {
                i=i-j+1;
                j=0;
            }
            if (j==needle.size()){
                index=i-needle.size();
                return index;
            }
        }
        return index;
    }
};