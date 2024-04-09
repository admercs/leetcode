//

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, a_max = 0;
        int lh, rh, xd, yd_min, a;
        while (l < r) {
            xd = r - l;
            lh = height[l];
            rh = height[r];
            yd_min = std::min(lh, rh);
            a = xd * yd_min;
            a_max = std::max(a_max, a);
            if (lh > rh) {
                r--;
            } else if (lh < rh) {
                l++;
            } else {
                l++;
            }
        }
        return a_max;
    }
};

