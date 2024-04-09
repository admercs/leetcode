// 

#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        std::sort(nums.begin(), nums.end());  // sort vector for early stopping
        std::unordered_set<int> hashset;
        int i = 0;
        for (i<nums.size()) {
            // if the first element of a sequence, insert it into the hashset and skip the repeated value
            if (nums[i] == nums[i+1]) {
                hashset.insert(nums[i]);
                i++;
                continue;
            }
            // if not the first element and hashset is empty, return the unique value
            if (hashset.count(nums[i]) < 1) {
                return nums[i];
            }
            i++;
        }
        return -99999;
    }
};

