#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int dist_min, sum_i, dist = INT_MAX;
        int n = size(nums)-2;
        int i = 0;
        int l, r, dist_i, dist_i_abs;
        while (i < n) {
            if (i && nums[i-1] == nums[i]) {
                i++;
                continue;
            }
            sum_i = nums[i] + nums[i+1] + nums[i+2];
            if (sum_i >= target) {
                dist_i = sum_i - target;
                if (dist_i < dist) {
                    dist_min = sum_i;
                    dist = dist_i;
                }
                break;
            }
            sum_i = nums[i] + nums[n] + nums[n+1];
            if (sum_i <= target) {
                dist_i = target - sum_i;
                if (dist_i < dist) {
                    dist_min = sum_i;
                    dist = dist_i;
                }
                i++;
                continue;
            }
            l = i + 1;
            r = n + 1;
            while (l < r) {
                sum_i = nums[i] + nums[r] + nums[l];
                if (sum_i == target) {
                    return target;
                }
                if (sum_i < target) {
                    l++;
                } else {
                    r--;
                }
                dist_i_abs = std::abs(sum_i - target);
                if (dist_i_abs < dist) {
                    dist_min = sum_i;
                    dist = dist_i_abs;
                }
            }
            i++;
        }
        return dist_min;
    }
};

