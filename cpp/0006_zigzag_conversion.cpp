#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::string result;
        int s_size = s.size();
        int step = (2*numRows)-2;
        int zag;
        int i = 0;
        int j;
        if (numRows == 1) return s;
        while (i<numRows) {
            j = i;
            while (j<s_size) {
                result.append({s[j]});
                zag = j+step-2*i;
                if (i != 0 && i != numRows-1 && zag < s_size) {
                    result.append({s[zag]});
                }
                j += step;
            }
            i++;
        }
        return result;
    }
};

