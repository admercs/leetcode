#include <string>
#include <array>
#include <vector>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result;
        if (digits.size() == 0) return result;
        std::array<std::string, 10> lut = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        std::string output;
        int index = 0;
        solve(digits, output, index, result, lut);
        return result;
    }
private:
    void solve(std::string& digits, std::string& output, int index, 
            std::vector<std::string>& result, std::array<std::string, 10>& lut) {
        if (index >= digits.size()) {
            result.push_back(output);
            return;
        }
        int i = 0;
        int number = digits[index] - '0';
        std::string value = lut[number];
        while (i<value.size()) {
            output.push_back(value[i]);
            solve(digits, output, index+1, result, lut);
            output.pop_back();
            i++;
        }
    }
};

