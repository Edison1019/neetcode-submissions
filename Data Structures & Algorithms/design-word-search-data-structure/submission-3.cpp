class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool end = false;
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int idx, TrieNode* cur){
        if (idx == word.size()) {
            return cur->end;
        }

        char c = word[idx];

        if (c == '.') {
            for (auto& [ch, next] : cur->children) {
                if (next != nullptr && dfs(word, idx + 1, next)) {
                    return true;
                }
            }
            return false;
        }

        auto it = cur->children.find(c);

        if (it == cur->children.end()) {
            return false;
        }

        return dfs(word, idx + 1, it->second);
    }
};
