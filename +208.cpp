class TrieNode {
public:
    TrieNode* childs[26];
    bool wordEnd;
    
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childs[i] = nullptr;
        }
    }   
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->childs[c - 'a']) { 
                TrieNode* node = new TrieNode();
                curr->childs[c - 'a'] = node;
            }
            curr = curr->childs[c - 'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(std::string word) const {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->childs[c - 'a']) {
                return false;
            }
            curr = curr->childs[c - 'a'];
        }
        return curr->wordEnd;
    }
    
    bool startsWith(std::string prefix) const {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->childs[c - 'a']) {
                return false;
            }
            curr = curr->childs[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
