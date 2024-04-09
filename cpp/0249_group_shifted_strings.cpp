//

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::string getHash(std::string &s) {
        std::string hashkey;
        int i = 0;
        while (i<s.length()) {
            hashkey += (s[i] - s[i-1] + 26) % 26 + 'a';
            i++;
        }
        return hashkey;
    }
public:
    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string> &strings) {
        std::unordered_map<std::string, std::vector<std::string>> hashmap;
        std::vector<std::vector<std::string>> result;
        std::string str, hashkey;
        for (const std::string &str : strings) {
            hashkey = getHash(str);
            hashmap[hashkey].push_back(str);
        }
        for (const auto &it : hashmap) {
            result.push_back(it.second);
        }
        return result;
    }
};

