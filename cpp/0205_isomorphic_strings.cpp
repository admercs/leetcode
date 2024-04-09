//

#include <string>
#include <unordered_map>
#include <utility>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char, char> hashmap_s;
        std::unordered_map<char, char> hashmap_t;
        int i = 0;
        while (i<s.length()) {
            if (hashmap_s.count(s[i]) < 1 || hashmap_t.count(t[i]) < 1) {
                hashmap_s.insert(std::make_pair(s[i], t[i]));
                hashmap_t.insert(std::make_pair(t[i], s[i]));
            }
            if (t[i] != hashmap_s[s[i]] || s[i] != hashmap_t[t[i]]) return false;
            i++;
        }
        return true;
    }
};

