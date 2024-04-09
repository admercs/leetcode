#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (std::all_of(nums.begin(), nums.end(), [&](const int i) { return i == 0; })) {
            return {{0,0,0}};
        }
        int min = *std::min_element(nums.begin(), nums.end());
        int max = *std::max_element(nums.begin(), nums.end());
        int i, j, exist, range, target;
        if (min >= 0 || max <= 0) return {};
        range = max-min+1;
        exist = 0;
        std::vector<int> count(range, 0);
        std::vector<std::vector<int>> triples;
        for (const int& i : nums) ++count[i-min];
        for (i=0; i < range; i++) {
            if (count[i] !=0) nums[exist++] = i+min;
        }
        auto l = nums.begin();
        auto r = next(l, exist-1);
        while (*l <=0){
            while (*r >= 0){
                target = -(*l + *r);
                if (target < *l) {
                    --r;
                    continue;
                }
                if (target > *r) break;
                if (((*l == target || *r == target) && count[target-min] == 1) || 
                ((*l == target && *r == target ) && count[target-min] == 2)){
                    --r;
                    continue;
                }
                if (count[target-min] !=0 ) triples.push_back({*l, target, *r});
                r--;
            }
            ++l;
            r = std::next(nums.begin(), exist - 1);
        }
        return triples;
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> result;
        std::vector<std::vector<int>> x;
        for (i=0; i<nums.size()-2; i++) {
            std::vector<std::vector<int>> temp = findTwoSum(nums, i+1, nums.size()-1, nums[i]*-1);
            for (j=0; j<temp.size(); j++) result.insert(temp[j]);
        }
        for (const auto& it : result) x.push_back(it);
        return x;
    }
    vector<vector<int>> findTwoSum(vector<int>& nums, int l, int r, int sum) {
        std::vector<std::vector<int>> result;
        int temp = 0;
        while (l<r) {
            temp = nums[l] + nums[r];
            if (temp == sum) result.push_back({sum*-1, nums[l++], nums[r--]});
            else if (temp > sum) r--;
            else l++;
        }
        return result;
    }
};

