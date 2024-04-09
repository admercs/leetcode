// 
#include <array>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        constexpr int N = 9;
        std::array<int,N> rows = {}, cols = {}, boxes = {};
        int val, pos, idx;
        int r = 0;
        int c = 0;
        while (r<N) {
            while (c<N) {
                if (board[r][c] == '.') continue;
                val = board[r][c] - '0';
                pos = 1 << (val - 1);

                if ((rows[r] & pos) > 0) return false;
                rows[r] |= pos;

                if ((cols[c] & pos) > 0) return false;
                cols[c] |= pos;

                idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) return false;
                boxes[idx] |= pos;

                c++;
            }
            r++;
        }
        return true;
    }
};

