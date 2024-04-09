#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result;
        bool diff;
        int i = 0;
        int j;
        while (i < strs[0].size()) {
            diff = false;
            j = 1;
            while (j < strs.size()) {
                if (strs[0][i] != strs[j][i]) {
                    diff = true;
                    break;
                }
                j++;
            }
            if (!diff) {
                result += strs[0][i];
            } else {
                break;
            }
            i++;
        }
        return result;
    }
};

