#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string result;
        int l, r, temp;
        int n = 0;
        int size = s.size();
        int i = 0;
        while (i<size) {
            // odd length
            l = i;
            r = i;
            while (l >= 0 && r < size && s[l] == s[r]) {
                temp = r-l+1;
                if (temp > n) {
                    n = temp;
                    result = s.substr(l, r+1-l);
                }
                l--;
                r++;
            }
            // even length
            l = i;
            r = i+1;
            while (l >= 0 && r < size && s[l] == s[r]) {
                temp = r-l+1;
                if (temp > n) {
                    n = temp;
                    result = s.substr(l, r+1-l);
                }
                l--;
                r++;
            }
            i++;
        }
        if (n == 0) {
            return {s[0]};
        }
        return result;
    }
};

