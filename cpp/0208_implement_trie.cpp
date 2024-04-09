/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

constexpr int NCHAR = 26;

class TrieNode{
public:
    TrieNode* child[NCHAR];
    bool isLeafNode;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word){
            if (!cur->child[c-'a']) {
                cur->child[c-'a'] = new TrieNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->isLeafNode = true;
    }

    bool search(string word) {
        TrieNode* cur=root;
        for (char c : word){
            if (!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        if (cur->isLeafNode) return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix){
            if (!cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }
        return true;
    }
};

