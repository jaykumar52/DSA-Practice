class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;
        while(j<chars.size()){
            int count=0;
            char c=chars[j];
            while (j<chars.size() && c==chars[j]){
                count++;
                j++;
            }
            chars[i++]=c;
            if (count>1){
                string s=to_string(count);
                for (char ch : s){
                    chars[i++]=ch;
                }
            }
        }
        return i;
    }
};