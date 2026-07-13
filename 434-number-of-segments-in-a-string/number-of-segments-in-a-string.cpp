class Solution {
public:
    int countSegments(string s) {
        int count =0;
        string word;
        stringstream ss(s);
        while (ss>>word){
            count++;
        }
        return count;
    }
};