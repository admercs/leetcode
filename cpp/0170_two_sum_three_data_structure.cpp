/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

#include <unordered_map>

class TwoSum {
    std::unordered_map<int64_t, int8_t> hashmap;
public:
    TwoSum() {}
    
    void add(int64_t number) { hashmap[number]++; }
    
    bool find(int64_t value) {
        int limit = 100000;
        if (value > limit || value < -limit) return false;
        int64_t cmpl;
        for (const auto &kv : hashmap) {
            cmpl = value - kv.first;
            if (hashmap.count(cmpl) == 0) continue;
            if (kv.first != cmpl || kv.second > 1) return true;
        }
        return false;
    }
};

