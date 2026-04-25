class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };

    TrieNode* root;

    bool searchWord(string word, int index, TrieNode* node) {
        if(index == word.size())
            return node->isEnd;

        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] && searchWord(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        }

        int ch = word[index] - 'a';
        if(node->children[ch] == NULL)
            return false;

        return searchWord(word, index + 1, node->children[ch]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        return searchWord(word, 0, root);
    }
};

/**
 
Your WordDictionary object will be instantiated and called as such:
WordDictionary* obj = new WordDictionary();
obj->addWord(word);
bool param_2 = obj->search(word);*/