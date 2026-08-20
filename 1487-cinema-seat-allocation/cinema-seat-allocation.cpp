class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_reserved;
        
        for (const auto& seat_pair : reservedSeats) {
            int row = seat_pair[0];
            int seat = seat_pair[1];
            if (seat >= 2 && seat <= 9) {
                row_reserved[row] |= (1 << (seat - 2));
            }
        }
        long long total_families = (long long)n * 2;
        const int left_mask = 15;
        const int right_mask = 240;
        const int middle_mask = 60;
        for (const auto& [row, mask] : row_reserved) {
            bool left_free = (mask & left_mask) == 0;
            bool right_free = (mask & right_mask) == 0;
            bool middle_free = (mask & middle_mask) == 0;
            
            if (left_free && right_free) {
                continue;
            } 
            else if (left_free || right_free || middle_free) {
                total_families -= 1;
            } 
            else {
                total_families -= 2;
            }
        }        
        return total_families;
    }
};