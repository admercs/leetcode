//

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hashmap;
        std::vector<std::vector<std::string>> result;
        std::string sorted;
        for (const std::string& str : strs) {
            sorted = str;
            sort(sorted.begin(), sorted.end());
            hashmap[sorted].push_back(str);
        }
        for (const auto& kv : hashmap) result.push_back(kv.second);
        return result;
    }
};

