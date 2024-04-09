//

#include <unordered_map>

class Solution {
private:
    int digit_sum_squares(int n) {
        int rem_sum_sq = 0;
        while (n) {
            rem_sum_sq += (n % 10) * (n % 10);
            n /= 10; 
        }
        return rem_sum_sq;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> hashset;
        while (n != 1) {
            n = digit_sum_squares(n);
            if (n == 1) return true;
            if (hashset.count(n) > 0) return false;
            hashset.insert(n);
        }
        return true;
    }
};

