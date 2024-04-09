// 
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int len = s.length(), iter = 0, sign = 1;
        long long int ret_val = 0;
        while (iter < len) {
            if(s[iter] != ' ') break;
            else ++iter;
        }
        if (s[iter] == '-'){ 
            sign = -1;
            ++iter;
        }
        else if (s[iter] == '+') ++iter;
        while (iter < len ) {
            if (s[iter] < '0' || s[iter] > '9') break;
            else if ((ret_val * 10 + (s[iter] - '0')) > 2147483648) {
                ret_val = 2147483648;
                break;
            }
            else {
                ret_val = ret_val*10 + (s[iter++] - '0');
            }
        }
        ret_val *= sign;
        if (ret_val == 2147483648) --ret_val;
        return ret_val;
    }
};

