// 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashmap[128] = {0};
        int slen = s.length();
        int l=0;
        int r=0;
        int n=0;
        char c;
        while (r<slen) {
            c = s[r];
            hashmap[c]++;
            while (hashmap[c] > 1) { 
                hashmap[s[l]]--;
                l++;
            }
            n = max(n, r-l+1);
            r++;
        }
        return n;
    }
};

