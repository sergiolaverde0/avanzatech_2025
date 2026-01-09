#include <string>
#include <vector>

class Impl1 {
public:
    Impl1(void) { }

    /// Since check iterates over all entries to find a match, it has O(n)
    /// complexity in time.
    /// Since the memory footprint is unrelated to the number of strings seen,
    /// it has O(1) complexity in space.
    bool check(const std::string& chain)
    {
        // C++ has a built-in method in vectors to check for this, but is not
        // being used in order to properly show how (in)efficient this
        // implementation actually is.
        for (const std::string& entry : this->string_list) {
            if (entry == chain) {
                return true;
            }
        }
        return false;
    }

    /// Add needs to call `check()` in order to avoid duplicate entries, so it
    /// must also be O(n) in time, even if adding items at the end of a vector
    /// is O(1) by itself.
    /// It stores all strings as-is, so space complexity is O(nl) where l is the
    /// length of the strings.
    void add(const std::string& chain)
    {
        if (this->check(chain)) {
            return;
        }
        this->string_list.push_back(chain);
    }

private:
    std::vector<std::string> string_list;
};

class Impl2 {
public:
    Impl2(void) { }

    /// Takes advantage of the list being sorted to perform a binary search,
    /// which makes it O(log n) in time complexity, and O(1) in space complexity.
    bool check(const std::string& chain)
    {
        int start = 0;
        int end = this->string_list.size() - 1;
        while (start <= end) {
            unsigned center = start + (end - start) / 2;
            if (this->string_list[center] == chain) {
                return true;
            } else if (chain < this->string_list[center]) {
                end = center - 1;
            } else {
                start = center + 1;
            }
        }
        return false;
    }

    /// It might use a binary search to find the place to insert into faster,
    /// but because it must push all the later entries down the list after doing
    /// so, it has O(n) time complexity.
    /// It stores all strings as-is, so space complexity is O(nl) where l is the
    /// length of the strings.
    void add(const std::string& chain)
    {
        // Insert the string and return early if the list is empty
        if (this->string_list.size() == 0) {
            this->string_list.push_back(chain);
            return;
        }
        int start = 0;
        int end = this->string_list.size() - 1;
        while (start <= end) {
            unsigned center = start + (end - start) / 2;
            if (this->string_list[center] == chain) {
                // If string has already been seen, do nothing
                return;
            } else if (chain < this->string_list[center]) {
                end = center - 1;
            } else {
                start = center + 1;
            }
        }
        // Otherwise, insert at its position to keep the list ordered
        this->string_list.insert(this->string_list.begin() + start, chain);
    }

private:
    std::vector<std::string> string_list;
};

class Impl3 {
public:
    /// Searching a trie has O(l) time and space complexity, where l is the
    /// string length. The number of strings seen so far is irrelevant.
    bool check(const std::string& chain)
    {
        return stringList.search(chain);
    }
    /// Inserting in a trie has O(l) time complexity, where l is string length.
    /// The number of strings seen so far is irrelevant.
    /// Space complexity is O(nl) in the worst case when strings have no common
    /// root, but average is closer to O(n).
    void add(const std::string& chain)
    {
        stringList.insert(chain);
    }

private:
    // Private classes to hide the implementation details of the trie data
    // structure.
    class TrieNode {
    public:
        // Easier than checking for the null character
        bool endOfWord;
        TrieNode()
        {
            // This needs to be a `resize` instead of a `reserve` to ensure
            // elements exist before accesing them.
            // 128 entries is just enough to hold the ASCII table, full UTF-8
            // support would be incredibly expensive in space.
            this->trie.resize(128, nullptr);
            endOfWord = false;
        }
        ~TrieNode()
        {
            for (TrieNode* entry : trie) {
                if (entry) {
                    delete entry;
                    entry = nullptr;
                }
            }
        }
        std::vector<TrieNode*> trie;
    };

    class Trie {
    private:
        TrieNode* root;

    public:
        Trie()
        {
            root = new TrieNode();
        }
        ~Trie()
        {
            delete root;
        }
        void insert(const std::string& chain)
        {
            TrieNode* node = this->root;
            // Use the characters to pick the next branch to go to
            for (char index : chain) {
                // If the branch doesn't exist, create one
                if (!node->trie[index]) {
                    node->trie[index] = new TrieNode();
                }
                node = node->trie[index];
            }
            // Marker to distinguish full matches from just substrings.
            node->endOfWord = true;
        }
        bool search(const std::string& chain)
        {
            TrieNode* node = this->root;
            for (char index : chain) {
                if (!node->trie[index]) {
                    return false;
                }
                node = node->trie[index];
            }
            if (!node->endOfWord) {
                return false;
            }
            return true;
        }
    };

    Trie stringList;
};
