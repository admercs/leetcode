// Write a function that takes the binary representation of a positive integer
// and returns the number of set bits it has (also known as the Hamming weight).

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int i = 0;
        while (i<32) {
            if (n & 0x1 << i) res++;
            i++;
        }
        return res;
    }
};

