class Solution {
public:
    int countSegments(string s) {
        int count =0;
        int i=0;
        bool flag = false;
        while (i<s.size()){
            while (i<s.size() && s[i]==' ') i++;
            while (i<s.size() && s[i]!=' '){
                i++;
                flag=true;
            }
            if (flag){
                flag=false;
                count++;
            }
        }
        return count;
    }
};