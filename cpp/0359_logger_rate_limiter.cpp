//

#include <string>
#include <unordered_map>

class Logger {
private:
    std::unordered_map<std::string,int> hashmap;
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, std::string message) {
        if (hashmap.count(message) > 0) {
            if (timestamp - hashmap[message] >= 0) {
                hashmap[message] = timestamp + 10;
                return true;
            } else {
                return false;
            }
        }
        hashmap[message] = timestamp + 10;
        return true;
    }
};

