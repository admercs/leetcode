//

#include <vector>
#include <algorithm>

class Solution {
public:
    int fourSumCount(vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::sort(nums1.begin(), nums1.end());
	    std::sort(nums2.begin(), nums2.end());
        std::sort(nums3.begin(), nums3.end());
        std::sort(nums4.begin(), nums4.end());
        int len = nums1.size();
        int low = std::min(nums1[0] + nums2[0], -nums3[len-1] - nums4[len-1]);
        int high = std::max(nums1[len-1] + nums2[len-1], -nums3[0] - nums4[0]);
        int max = high - low + 1;
        int lut[max];
        memset(lut, 0, sizeof(lut));
        int count = 0;
        //int i;
        //for (i=0; i<size; i++) lut[i] = 0;
        for (const int &n : nums1) {
            for (int &m : nums2) {
                lut[n+m-low]++;
            }
        }
        for (const int &n : nums3) {
            for (int &m : nums4) {
                if (lut[-n-m-low] > 0) count += lut[-n-m-low];
            }
        }
        return count;
    }
};

