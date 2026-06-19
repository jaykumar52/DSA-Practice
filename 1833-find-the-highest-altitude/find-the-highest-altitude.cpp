class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size()+1, 0);
        int maxAltitude=0;

        for (int i=0; i<gain.size(); i++){
            altitude[i+1]=altitude[i]+gain[i];
            maxAltitude=max(maxAltitude, altitude[i+1]);
        }
        return maxAltitude;
    }
};