//

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> result;
        int k = nums2.size();
        int i = 0;
        int j = 0;
        while (i<nums1.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                if (j+1<k) {
                    ++j;
                } else {
                    return result;
                }
            } else if (nums1[i] < nums2[j]) {
                continue;
            } else if (nums1[i] > nums2[j]) {
                if (j+1<k) {
                    --i;
                    ++j;
                } else {
                    return result;
                }
            } else {
                return {};
            }
            i++;
        }
        return result;
    }
};

