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
public:
    TrieNode* root;

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
    
    bool search(std::string word, TrieNode* start) const {
        TrieNode* curr = start;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto child : curr->childs) {
                    if (child && this->search(word.substr(i + 1), child)) {
                        return true;
                    }
                }
                return false;
            }
            else if (!curr->childs[c - 'a']) {
                return false;
            }
            else {
                curr = curr->childs[c - 'a'];
            }
        }
        return curr->wordEnd;
    }
};

class WordDictionary {
private:
    Trie* dict;
public:
    WordDictionary() {
        dict = new Trie();
    }
    
    void addWord(std::string word) {
        dict->insert(word);        
    }
    
    bool search(std::string word) {
        return dict->search(word, dict->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
