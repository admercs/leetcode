// 

#include <array>
#include <string>

std::array<std::string, 4>  mille  = {"", "M", "MM", "MMM"};
std::array<std::string, 10> centum = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
std::array<std::string, 10> decem  = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
std::array<std::string, 10> unum   = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    std::string intToRoman(int num) {
        int temp = num / 1000;
        return mille[temp] + centum[temp/100] + decem[num%100/10] + unum[num%10];
    }
};

