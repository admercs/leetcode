#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
        size_t size = nums1.size();
        double midpoint = static_cast<double>(size) / 2.0;
        bool is_even = size % 2 == 0 ? true : false;
        if (is_even) {
            return ((nums1[midpoint-1] + nums1[midpoint]) / 2.0);
        } else {
            return nums1[std::floor(midpoint)];
        }
    }
};

