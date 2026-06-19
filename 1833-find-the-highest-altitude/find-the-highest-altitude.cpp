class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int preAltitude=0;
        int maxAltitude=0;

        for (int i=0; i<gain.size(); i++){
            preAltitude=preAltitude+gain[i];
            maxAltitude=max(maxAltitude, preAltitude);
        }
        return maxAltitude;
    }
};