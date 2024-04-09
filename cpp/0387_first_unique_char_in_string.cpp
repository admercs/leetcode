//

#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> hashmap;
        for (const char& c : s) hashmap[c]++;
        int i = 0;
        while (i<s.length()) {
            if (hashmap[s[i]] == 1) return i;
            i++;
        }
        return -1;
    }
};

