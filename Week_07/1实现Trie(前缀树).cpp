class Trie {
public:
    /** Initialize your data structure here. */
    bool isEnd=false;
    Trie *next[26]={nullptr};
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root=this;
        for(auto nowWord:word)
        {
            if(root->next[nowWord-'a']==nullptr) root->next[nowWord-'a']=new Trie();
            root=root->next[nowWord-'a'];
        }
        root->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root=this;
        for(auto nowWord:word)
        {
            if(root->next[nowWord-'a']==nullptr) return false;
            root=root->next[nowWord-'a'];
        }
        return root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root=this;
        for(auto nowWord:prefix)
        {
            if(root->next[nowWord-'a']==nullptr) return false;
            root=root->next[nowWord-'a'];
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