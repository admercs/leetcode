// 

class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        int rev = 0;
        int rem;
        if (x < 0) return false;
        while (n != 0) {
            if (abs(rev) > 214748364) return false;
            rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        if (x == rev) return true;
        return false;
    }
};

