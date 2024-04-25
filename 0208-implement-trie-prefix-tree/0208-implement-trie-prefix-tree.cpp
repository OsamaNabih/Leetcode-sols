class Node {
public:
    Node* child[26];
    bool isWord;
    Node() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* ptr = root;
        for (auto& c : word) {
            int i = c - 'a';
            if (!ptr->child[i]) ptr->child[i] = new Node();
            ptr = ptr->child[i];
        }
        ptr->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        Node* ptr = root;
        for (auto& c : word) {
            int i = c - 'a';
            if (!ptr->child[i]) return false;
            ptr = ptr->child[i];
        }
        if (prefix == false) return ptr->isWord;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */