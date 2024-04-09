//

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());  // unique values
        std::unordered_set<int> set2(nums2.begin(), nums2.end());  // unique values
        std::vector<int> result;
        for (const int& n1 : set1) {
            if (set2.count(n1) == 1) result.push_back(n1);  // if n1 in set2, add to results
        }
        return result;
    }
};

