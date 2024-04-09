/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

#include <string>
#include <vector>
#include <unordered_map>

class ValidWordAbbr {
private:
    std::unordered_map<std::string, std::vector<std::string>> revmap;
    
    std::string getAbbr(std::string& str) {
        int len = str.length();
        if (len < 3) return str;
        char first = str[0];
        char last  = str[len-1];
        return {first, (char)(len-2), last};
    }
    
public:
    ValidWordAbbr(std::vector<std::string>& dictionary) {
        //int size = dictionary.size();
        //if (size < 1 || size > 30000) revmap = {};
        int wlen;
        std::string abbr;
        for (const std::string &word : dictionary) {
            wlen = word.length();
            if (wlen < 1 || wlen > 20) continue;
            abbr = getAbbr(word);
            revmap[abbr].push_back(word);
        }
    }
    
    bool isUnique(std::string word) {
        std::string abbr = getAbbr(word);
        if (revmap.count(abbr) < 1) return true;
        if (revmap[abbr].size() > 1 && revmap[abbr][0] != revmap[abbr][1]) return false;
        if (revmap[abbr][0] == word) return true;
        return false;
    }
};

