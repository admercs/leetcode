//

#include <cstdlib>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> hashmap;
        int i = 0;
        while (i<nums.size()) {
            if (hashmap.count(nums[i]) > 0) {
                 if (std::abs(i - (hashmap[nums[i]])) <= k) return true;
            }
            hashmap[nums[i]] = i;
            i++;
        }
        return false;
    }
};

