// 

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int rem;
        int upper = INT_MAX / 10;
        int lower = INT_MIN / 10;
        while (x != 0) {
            rem = x % 10;
            x /= 10;
            if (rev > upper || rev == upper && rem > 7) {
                return 0;
            }
            if (rev < lower || rev == lower && rem < -8) {
                return 0;
            }
            rev = rev * 10 + rem;
        }
        return rev;
    }
};

