class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool end = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;

        for (char c : word) {
            if (cur->child[c] == nullptr) {
                cur->child[c] = new TrieNode();
            }
            cur = cur->child[c];
        }

        cur->end = true;
    }

    bool dfs(string word, int idx, TrieNode* cur) {
        if (idx == word.size()) {
            return cur->end;
        }

        char c = word[idx];

        if (c == '.') {
            for (auto& [ch, next] : cur->child) {
                if (next != nullptr && dfs(word, idx + 1, next)) {
                    return true;
                }
            }
            return false;
        }

        auto it = cur->child.find(c);

        if (it == cur->child.end() || it->second == nullptr) {
            return false;
        }

        return dfs(word, idx + 1, it->second);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};