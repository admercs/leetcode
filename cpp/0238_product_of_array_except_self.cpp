//

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res(n, 1);
        int n = nums.size();
        int from_begin = 1;
        int from_end = 1;
        int i = 0;
        while (i<n) {
            res[i] *= from_begin;
            from_begin *= nums[i];
            res[n-i-1] *= from_end;
            from_end *= nums[n-i-1];
            i++;
        }
        return res;
    }
};

