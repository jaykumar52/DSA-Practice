class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s){
            count[c-'a']++;
        }
        int oddCount=0;
        int oddIndex=-1;
        for (int i=0; i<26; i++){
            if (count[i]%2==1){
                oddCount++;
                oddIndex=i;
            }
        }
        if (oddCount>1) return "";
        string firstHalf="";
        for (int i=0; i<26; i++){
            firstHalf.append(count[i]/2, i+'a');
        }
        
        string secondHalf=firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (oddIndex!=-1) {
            char mid='a'+oddIndex;
            return firstHalf+mid+secondHalf;
        }
        return firstHalf+secondHalf;
    }
};