/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 **/

#include <vector>
#include <unordered_map>
#include <algorithm>

class RandomizedSet {
private:
    std::unordered_map<int, int> map;
    std::vector<int> vec;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);  
    }
    
    bool insert(int val) {
        if (map.count(val)) return false;
        vec.push_back(val);
        map[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (map.count(val) == 0) return false;
        int current = map[val];
        int last = vec.size()-1;
        std::swap(vec[last], vec[current]);
        map[vec[current]] = current;
        vec.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() { return vec[std::rand() % vec.size()]; }
};

