//

#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> hashset;
        for (const int& num : nums) {
            if (hashset.count(num) > 0) {
                return true;
            } else {
                hashset.insert(num);
            }
        }
        return false;
    }
};
