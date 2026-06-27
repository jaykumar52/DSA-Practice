class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length()<=2 || numRows==1) return s;
        int index1=2*numRows-2;
        int index2=0;
        string ans;
        for (int i=0; i<numRows; i++){
            int j=i;
            while(j<s.size()){
                
                if (index1!=0 && j<s.size()){
                    ans.push_back(s[j]);
                    j=j+index1;
                }
                if (index2!=0 && j<s.size()){
                    ans.push_back(s[j]);
                    j=j+index2;
                }
            }

            index1-=2;
            index2+=2;
            
        }
        return ans;
    }
};