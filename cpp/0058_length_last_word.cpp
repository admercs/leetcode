//

class Solution {
public:
    int lengthOfLastWord(string s) {
        bool spaced = false;
        int n = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                if (spaced) {
                    n = 0;
                    spaced = false;
                }
                n++;
            } else {
                spaced = true;
            }
            i++;
        }
        return n;
    }
};

