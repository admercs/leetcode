//

#include <vector>
#include <unordered_map>
#include <utility>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> hashmap;
        for (const auto &n : nums) { hashmap[n]++; }
        std::vector<std::pair<int,int>> revmap(hashmap.size());
        std::vector<int> res(k, 0);
        int i=0;
        for (const auto &kv : hashmap) {
            revmap[i] = {kv.second, kv.first};
            i++;
        }
        sort(revmap.begin(), revmap.end(), [&](const auto &a, const auto &b) {
            return a.first > b.first;
        });
        i = 0;
        while (i<k) {
            res[i] = revmap[i].second;
            i++;
        }
        return res;
    }
};

