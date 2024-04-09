//

#include <unordered_map>

std::unordered_map<char,int> hashmap ({
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
});

class Solution {
  public:
    int romanToInt(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int sum = 0;
        int i = 0;
        while (i<n-1) {
            if (hashmap[s[i]] < hashmap[s[i+1]]) {
                sum -= hashmap[s[i]];
            } else {
                sum += hashmap[s[i]];
            }
            i++;
        }
        sum += hashmap[s[n-1]];
        return sum;
    }
};

