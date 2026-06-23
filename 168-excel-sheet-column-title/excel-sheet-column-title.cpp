class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        int q=columnNumber/26;
        int r=columnNumber%26;
        if (r==0) {
            r=26;
            q--;
        }
        while(q>26){
            if (r) s.insert(s.begin(), 'A'+r-1);
            r=q%26;
            if (r==0) {
                r=26;
                q--;
            }
            q=q/26;
        }
        if (r) s.insert(s.begin(), 'A'+r-1);
        if (q) s.insert(s.begin(), 'A'+q-1);
        return s;
    }
};