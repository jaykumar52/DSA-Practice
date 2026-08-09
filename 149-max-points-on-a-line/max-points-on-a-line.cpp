class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if (n<=2) return n;

        int maxPoints=0;
        for (int i=0; i<n; i++){
            unordered_map<string, int> map;
            int currMax=0;
            for (int j=i+1; j<n; j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                int gcdVal=gcd(dx,dy);
                dx=dx/gcdVal;
                dy=dy/gcdVal;
                if (dx<0){
                    dx=-dx;
                    dy=-dy;
                }
                else if (dx==0){
                    dy=1;
                }
                string slopeKey=to_string(dx)+to_string(dy);
                map[slopeKey]++;
                currMax=max(currMax, map[slopeKey]);
            }
            maxPoints=max(maxPoints, currMax);
        }
        return maxPoints+1;
    }
};