class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size()>magazine.size()) return false;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i=0;
        int j=0;
        while(i<ransomNote.size() && j<magazine.size()){
            if (ransomNote[i]==magazine[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if (i==ransomNote.size()) return true;
        else return false;
    }
};