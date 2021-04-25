#include <vector>
#include <string>

using namespace std;
class Trie
{
private:
    vector<Trie *> children;
    bool is_end;

    Trie *search_prefix(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }

            node = node->children[ch];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), is_end(false)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;

        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = search_prefix(word);

        return node != nullptr && node->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return search_prefix(prefix) != nullptr;
    }
};