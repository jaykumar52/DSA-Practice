class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<words[i].size(); j++){
                mask[i]=mask[i] | (1<<(words[i][j]-'a'));
            }
        }
        int ans=0;
        for (int i=0; i<words.size()-1; i++){
            for (int j=i+1; j<words.size(); j++){
                if ((mask[i] & mask[j])==0) 
                ans=max(ans, (int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};